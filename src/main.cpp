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

int	main(int ac, char **av)
{
    Lexer   lex;
	//Parser  par;
	std::vector<std::string> stringCommands;

	try
	{
		if (ac == 1)
			stringCommands = lex.readUserInput();
		else if (ac == 2)
            stringCommands = lex.readFromFile(av[1]);
		else
			std::cout << "Enter ONE file name or without parameters !\n";
	}
	catch(std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
    catch(Lexer::FileOpenException &e)
    {
        std::cerr << "File can't be opened! -> "  << e.what() << std::endl;
    }
    catch(Lexer::WrongCommandException &e)
    {
        std::cerr << "Unknown command -> "  << e.what() << std::endl;
    }
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
