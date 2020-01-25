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

int	main(int ac, char **av)
{
	Parser par;

	try
	{
		if (ac == 1)
			par.readUserInput();
		else if (ac == 2)
			par.readFromFile(av[1]);
		else
			std::cout << "Enter ONE file name or without parameters !\n";
	}
	catch(std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
