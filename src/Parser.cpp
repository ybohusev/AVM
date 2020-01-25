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
	Parser::initCommands();
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

void Parser::initCommands()
{
	commands.push_back(new Push());
	commands.push_back(new Pop());
	commands.push_back(new Dump());
	commands.push_back(new Assert());
	commands.push_back(new Add());
	commands.push_back(new Sub());
	commands.push_back(new Mul());
	commands.push_back(new Div());
	commands.push_back(new Mod());
	commands.push_back(new Print());

	nameCommands.push_back("push");
	nameCommands.push_back("pop");
	nameCommands.push_back("dump");
	nameCommands.push_back("assert");
	nameCommands.push_back("add");
	nameCommands.push_back("sub");
	nameCommands.push_back("mul");
	nameCommands.push_back("div");
	nameCommands.push_back("mod");
	nameCommands.push_back("print");
	nameCommands.push_back("exit");
}

void Parser::doCommand(std::vector<IOperand const *> *v, std::string line)
{
	std::stringstream ss(line);
	std::string aux;
	size_t i;
	std::getline(ss, aux, ' ');
    //std::cout << aux << std::endl;
    if (aux[0] != ';')
	{
		for (i = 0; i < commands.size(); i++)
		{
			if (aux == nameCommands.at(i))
			{
				commands.at(i)->doCommands(v, line);
				break ;
			}
			else if (aux == "exit")
				std::exit(0);
		}
		if (i == commands.size())
			throw WrongCommandException();
	}
}

void Parser::checkExit(std::string const &line)
{
	size_t found;

	found = line.find("exit");
	if (found == std::string::npos)
		throw NoExitException();
}

void Parser::readFromFile(std::string const &filename)
{
	std::string line;
	std::ifstream fin(filename);
	std::ifstream fin1(filename);
	std::vector<IOperand const *> v;

	if (!fin.is_open() && !fin1.is_open())
	{
		throw FileOpenException();
	}
	else
	{
		std::getline(fin1, line, '\0');
		checkExit(line);
		while (std::getline(fin, line))
			doCommand(&v, line);
	}
}

void Parser::readUserInput()
{
	std::string line;
	std::string userInput;
	std::vector<IOperand const *> v;
	std::string to;

	while (std::getline(std::cin, line) && line != ";;")
		userInput += line + "\n";
	checkExit(userInput);
	std::stringstream ss(userInput);
	while(std::getline(ss, to, '\n'))
		doCommand(&v, to);

}

const char* Parser::FileOpenException::what() const noexcept
{
	return ("File can't be opened!");
}

const char* Parser::NoExitException::what() const noexcept
{
	return ("Exception: No Exit command !");
}

const char* Parser::WrongCommandException::what() const noexcept
{
	return ("Exception: Wrong command !");
}
