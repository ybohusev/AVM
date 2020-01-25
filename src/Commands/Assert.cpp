/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:01:05 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:01:09 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Assert.hpp"

Assert::Assert()
{
	initNameType();
}

Assert::Assert(Assert const &obj)
{
	*this = obj;
}

Assert& Assert::operator=(Assert const &obj)
{
	(void)obj;
	return *this;
}

Assert::~Assert()
{
}

void Assert::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	std::string aux;
	std::stringstream ss(line);
	size_t i;

	if (v->size() == 0)
		throw Commands::EmpyStackException();
	std::getline(ss, aux, ' ');
	std::getline(ss, aux, '(');
	if (aux.length() == 0)
		throw Commands::WrongTypeException();
	for (i = 0; i < nameType.size(); i++)
	{
		if (aux == nameType.at(i))
		{
			std::getline(ss, aux, ')');
			if (aux.length() == 0)
				throw Commands::WrongValueException();
			if (std::stod(v->back()->toString()) == std::stod(aux) && v->back()->getType() == i)
				break;
			else
				throw DifferentValueException();
		}
	}
	if (i == nameType.size())
		throw Commands::WrongTypeException();
}

Assert::DifferentValueException::DifferentValueException()
{
}

Assert::DifferentValueException::~DifferentValueException() throw()
{
}

Assert::DifferentValueException::DifferentValueException(DifferentValueException const &obj)
{
	*this = obj;
}

Assert::DifferentValueException& Assert::DifferentValueException::operator=(DifferentValueException const &obj)
{
	(void)obj;
	return *this;
}

const char* Assert::DifferentValueException::what() const throw()
{
	return ("Exception: Different value or type !");
}
