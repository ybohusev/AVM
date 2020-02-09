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
#include "Commands/CommandsSet.hpp"
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

public:
	Parser();
	Parser(Parser const &obj);
	~Parser();
	Parser &operator=(Parser const &obj);
    std::vector<Commands *> parseCommands(std::vector<std::string> &comStrings);
	static Commands* initCommands(eCommandType com, eOperandType arg=UNKNOWN, const std::string& value=std::string());
	void pushComToStack(const std::string& com);
};

#endif
