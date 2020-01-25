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

Print::Print()
{
}

Print::Print(Print const &obj)
{
	*this = obj;
}

Print& Print::operator=(Print const &obj)
{
	(void)obj;
	return *this;
}

Print::~Print()
{
}

void Print::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() == 0)
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
	(void)line;
}

Print::NotEightTypeException::NotEightTypeException()
{
}

Print::NotEightTypeException::~NotEightTypeException() throw()
{
}

Print::NotEightTypeException::NotEightTypeException(NotEightTypeException const &obj)
{
	*this = obj;
}

Print::NotEightTypeException& Print::NotEightTypeException::operator=(NotEightTypeException const &obj)
{
	(void)obj;
	return *this;
}

const char* Print::NotEightTypeException::what() const throw()
{
	return ("Exception: Invalid type (value at the top of the stack is not 8 bit integer) !");
}
