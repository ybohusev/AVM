/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:59:35 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 15:59:39 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"
#include "Lexer.hpp"
#include "Commands/Commands.hpp"

bool file_analysis(std::vector<std::string>& comStrings, const std::string& file=std::string())
{
    Lexer   lex;

    try
    {
        if (file.empty())
            comStrings = lex.readUserInput();
        else
            comStrings = lex.readFromFile(file);
        return true;
    }
    catch(Lexer::FileOpenException &e)
    {
        std::cerr << "\033[1;31m" << "ERROR:" << "\033[0m" << " " << e.what() << std::endl;
    }
    catch(LexicalError &e)
    {
        std::cerr << "\033[1;31m" << "LEXICAL ERROR:" << "\033[0m" << " " << e.what() << std::endl;
    }
    catch(SyntaxError &e)
    {
        std::cerr << "\033[1;31m" << "SYNTAX ERROR:" << "\033[0m" << " " << e.what() << std::endl;
    }

    return false;
}

std::vector<Commands *> parseCommands(std::vector<std::string> &comStrings)
{
    Parser  par;
    return par.parseCommands(comStrings);
}

bool act(std::vector<Commands*> commands)
{
    std::vector<IOperand const *> stack;
    try
    {
        for (const auto &command : commands) {
            command->doCommands(&stack);
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    for (auto &comm : commands)
    {
        delete comm;
    }
    for (auto &op : stack)
    {
        delete op;
    }
    return true;
}

int	main(int ac, char **av)
{
    bool isFileValid;
    std::vector<std::string> comStrings;

    if (ac == 1)
        isFileValid = file_analysis(comStrings);
    else if (ac == 2)
        isFileValid = file_analysis(comStrings, av[1]);
    else
    {
        std::cout << "Enter ONE file name or without parameters !\n";
        std::exit(1);
    }

    if (isFileValid)
        act(parseCommands(comStrings));
	return 0;
}
