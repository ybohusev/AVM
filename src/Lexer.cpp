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
}

std::string Lexer::errLine;

Lexer::Lexer(Lexer const &obj)
{
    *this = obj;
}

Lexer& Lexer::operator=(Lexer const &obj)
{
    this->commands = obj.commands;
    return *this;
}

Lexer::~Lexer()
{
    if (fin.is_open())
        fin.close();
    std::cout << "Lexer destructor" << std::endl;
}

bool Lexer::checkLex(std::string line)
{
    std::string aux;
    size_t i;

    line = line.substr(0, line.find_first_of(';'));
    //std::cout << line << std::endl;

    if (line.size())
    {
        std::vector<std::string> comStr = splitString(line, ' ');
        eCommandType comType = gCommandSet.find(comStr[0])->second;

        switch (comType)
        {
            case eCommandType::UNKNOWN:
                errLine = line;
                throw WrongCommandException();
            case eCommandType::PUSH:
                commands.push_back(line);
                break;
            case eCommandType::ASSERT:
                commands.push_back(line);
                break;
            case eCommandType::EXIT:
                return true;
            default:
                commands.push_back(line);
                break;

        };
    }
    return false;
}

std::vector<std::string> Lexer::splitString(std::string com, char delim)
{
    std::vector<std::string> strings;
    std::istringstream f(com);
    std::string s;
    while (getline(f, s, delim)) {

        //std::cout << s << std::endl;
        strings.push_back(s);
    }
    return strings;
}

std::vector<std::string> Lexer::readFromFile(std::string const &filename)
{
    std::string line;
    bool isExit = false;
    fin.open(filename);

    if (!fin.is_open())
    {
        errLine = filename;
        throw FileOpenException();
    }
    else
    {
        while (!isExit && std::getline(fin, line))
            isExit = checkLex(line);
        if (!isExit)
            throw NoExitException();
    }
    return commands;
}

std::vector<std::string> Lexer::readUserInput()
{
    std::string line;
    std::string userInput;
    std::string to;

    while (std::getline(std::cin, line) && line != ";;")
        userInput += line + "\n";
    //checkExit(userInput);
    std::stringstream ss(userInput);
    while(std::getline(ss, to, '\n'));
    //pushComToStack(&v, to);

}

const char* Lexer::FileOpenException::what() const noexcept
{
    return (errLine.data());
}

const char* Lexer::NoExitException::what() const noexcept
{
    return ("Exception: No Exit command !");
}

const char* Lexer::WrongCommandException::what() const noexcept
{
    return (errLine.data());
}

