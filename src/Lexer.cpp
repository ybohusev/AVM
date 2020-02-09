/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 16:35:24 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/26 16:35:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Lexer.hpp"


Lexer::Lexer()
{
    isExit = false;
}

std::string Lexer::errLine;

Lexer::Lexer(Lexer const &obj)
{
    *this = obj;
}

Lexer& Lexer::operator=(Lexer const &obj)
{
    this->isExit = obj.isExit;
    this->commands = obj.commands;
    return *this;
}

Lexer::~Lexer()
{
    if (fin.is_open())
        fin.close();
}

bool Lexer::isNumber(std::string& st)
{
    bool wasDot = false;

    std::string::const_iterator it = st.begin();
    while (it != st.end())
    {
        if (!std::isdigit(*it) && (*it == '.' || st[0] == '-') && st[0] != '.' && st[st.size() - 1] != '.')
        {
            if (!wasDot)
                wasDot = true;
            else
                break;
        }
        else if (!std::isdigit(*it))
            break;
        ++it;
    }
    return !st.empty() && it == st.end();
}

eCommandType Lexer::checkComLex(std::string& com)
{
    eCommandType comType = gCommandSet.find(com)->second;
    if(!gCommandSet.count(com))
        throw WrongCommandException();
    if (comType == eCommandType::EXIT)
        isExit = true;
    return comType;
}

void Lexer::checkOpTypeLex(std::string& OpType, eCommandType comType)
{
    if (comType != eCommandType::ASSERT && comType != eCommandType::PUSH)
        throw commandSignException();
    if (OpType.find('(') == std::string::npos || OpType.find(')') == std::string::npos)
        throw missedBracketsException();
    int argPos = OpType.find('(');
    if (!gOperandTypeSet.count(OpType.substr(0, argPos)))
        throw WrongOperandTypeException();
    std::string arg = OpType.substr(argPos + 1, OpType.size() - argPos - 2);
    if (!isNumber(arg))
        throw invalidArgumentException();
}

void Lexer::checkLex(std::string line)
{
    std::string aux;

    line = line.substr(0, line.find_first_of(';'));
    if (!line.empty())
    {
        std::vector<std::string> comStr = splitString(line, ' ');
        eCommandType comType = checkComLex(comStr[0]);
        if (comStr.size() == 1 && (comType == eCommandType::ASSERT || comType == eCommandType::PUSH))
            throw commandSignException();
        if (comStr.size() > 2)
            throw unexpectedSybmbolException();
        if (comStr.size() > 1)
            checkOpTypeLex(comStr[1], comType);
        if (comType != eCommandType::EXIT && !isExit) {
            commands.push_back(line);
        }
    }
}

std::vector<std::string> Lexer::splitString(std::string& com, char delim)
{
    std::vector<std::string> strings;
    std::istringstream f(com);
    std::string s;
    while (getline(f, s, delim))
        strings.push_back(s);
    return strings;
}

std::vector<std::string> Lexer::readFromFile(std::string const &filename)
{
    std::string line;
    fin.open(filename);

    if (!fin.is_open())
    {
        errLine = filename;
        throw FileOpenException();
    }
    else
    {
        while (std::getline(fin, line))
        {
            errLine = line;
            checkLex(line);
        }
        if (!isExit)
            throw NoExitException();
    }
    return commands;
}

std::vector<std::string> Lexer::readUserInput()
{
    std::string line;
    std::stringstream userInput;

    while (std::getline(std::cin, line) && line != ";;")
        userInput << line << std::endl;
    std::cout << std::endl;
    while (std::getline(userInput, line))
    {
        errLine = line;
        checkLex(line);
    }
    if (!isExit)
        throw NoExitException();

    return commands;
}

const char* Lexer::FileOpenException::what() const noexcept
{
    errLine = "Can not open file " + errLine;
    return (errLine.c_str());
}

const char* Lexer::NoExitException::what() const noexcept
{
    return ("No Exit command!");
}

const char* Lexer::WrongCommandException::what() const noexcept
{
    errLine = "Unknown command in line -> " + errLine;
    return (errLine.data());
}

const char* Lexer::WrongOperandTypeException::what() const noexcept
{
    errLine = "Unknown operand type in line -> " + errLine;
    return (errLine.data());
}

const char* Lexer::commandSignException::what() const noexcept
{
    errLine = "command signature error argument -> " + errLine;
    return (errLine.data());
}

const char* Lexer::unexpectedSybmbolException::what() const noexcept
{
    errLine = "Unexpected symbol in line -> " + errLine;
    return (errLine.c_str());
}
const char* Lexer::missedBracketsException::what() const noexcept
{
    errLine = "Missed brackets in line -> " + errLine;
    return (errLine.data());
}
const char* Lexer::invalidArgumentException::what() const noexcept
{
    errLine = "Invalid argument in line -> " + errLine;
    return (errLine.data());
}

