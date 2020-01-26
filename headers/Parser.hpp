/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:06:38 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:06:42 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_PARSER_HPP
#define ABSTRACTVM_PARSER_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include "Commands/Commands.hpp"
#include "../headers/Commands/Push.hpp"
#include "../headers/Commands/Pop.hpp"
#include "../headers/Commands/Dump.hpp"
#include "../headers/Commands/Assert.hpp"
#include "../headers/Commands/Add.hpp"
#include "../headers/Commands/Sub.hpp"
#include "../headers/Commands/Mul.hpp"
#include "../headers/Commands/Div.hpp"
#include "../headers/Commands/Mod.hpp"
#include "../headers/Commands/Print.hpp"

class Parser
{
private:
	std::vector<Commands *> commands;
	std::vector<std::string> nameCommands;

public:
	Parser();
	Parser(Parser const &obj);
	~Parser();
	Parser &operator=(Parser const &obj);
	void readFromFile(std::string const &filename, std::vector<Commands> &stackCommands);
	void readUserInput();
	void initCommands();
	void pushComToStack(std::vector<Commands> &stackCommands, std::string line);
	void checkExit(std::string const &filename);

class FileOpenException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class NoExitException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class WrongCommandException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};
};

#endif
