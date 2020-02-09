/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:59:17 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 15:59:21 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Parser.hpp"


Parser::Parser()
{
}

Parser::Parser(Parser const &obj)
{
	*this = obj;
}

Parser& Parser::operator=(Parser const &obj)
{
	commands = obj.commands;
	return *this;
}

Parser::~Parser()
{
}

Commands* Parser::initCommands(eCommandType com, eOperandType arg, const std::string& value)
{
    Commands * tmp = nullptr;

    switch (com)
    {
        case eCommandType::PUSH:
            tmp = new Push(value, arg);
            break;
        case eCommandType::ADD:
            tmp = new Add();
            break;
        case eCommandType::ASSERT:
            tmp = new Assert(value, arg);
            break;
        case eCommandType::DIV:
            tmp = new Div();
            break;
        case eCommandType::DUMP:
            tmp = new Dump();
            break;
        case eCommandType::MOD:
            tmp = new Mod();
            break;
        case eCommandType::MUL:
            tmp = new Mul();
            break;
        case eCommandType::POP:
            tmp = new Pop();
            break;
        case eCommandType::PRINT:
            tmp = new Print();
            break;
        case eCommandType::SUB:
            tmp = new Sub();
            break;
        case eCommandType::UNKNOWN:
        case eCommandType::EXIT:
            break;
    };
    return  tmp;
}

void Parser::pushComToStack(const std::string& com)
{
	std::stringstream ss(com);
	std::string aux;

	std::getline(ss, aux, ' ');

    eCommandType comType = gCommandSet.find(aux)->second;
    std::getline(ss, aux, '(');
    if (!gOperandTypeSet.count(aux))
        commands.push_back(initCommands(comType));
    else
    {
        eOperandType type = gOperandTypeSet.find(aux)->second;
        int argPos = com.find('(');
        std::string arg = com.substr(argPos + 1, com.size() - argPos - 2);
        commands.push_back(initCommands(comType, type, arg));
    }

}

std::vector<Commands *> Parser::parseCommands(std::vector<std::string> &comStrings)
{
    for (const auto & comString : comStrings)
    {
        pushComToStack(comString);
    }
    return commands;
}
