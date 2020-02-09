/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:03:02 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:03:04 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Print.hpp"

Print::~Print()
{
}

void Print::doCommands(std::vector<IOperand const *> *v)
{
	if (v->empty())
		throw Commands::EmpyStackException();
	if (v->back()->getType() == 0)
	{
		if (isprint(std::stoi(v->back()->toString())))
			std::cout << static_cast<char>(std::stoi(v->back()->toString())) << std::endl;
		else
			std::cout << "Not printable char\n" << std::endl;
	}
	else
		throw NotEightTypeException();
}

const char* Print::NotEightTypeException::what() const noexcept
{
	return ("Exception: Invalid type (value at the top of the stack is not 8 bit integer) !");
}
