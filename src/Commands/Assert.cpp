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
}

Assert::Assert(const std::string& value_, eOperandType type_)
{
    value = value_;
    type = type_;
}

Assert::Assert(Assert const &obj)
{
	*this = obj;
}

Assert& Assert::operator=(Assert const &obj)
{
	if (this == &obj)
	    return *this;
	this->value = obj.value;
	this->type = obj.type;
    return *this;
}

Assert::~Assert()
{
}

void Assert::doCommands(std::vector<IOperand const *> *v)
{

	if (v->empty())
		throw Commands::EmpyStackException();
	if (std::stod(v->back()->toString()) != std::stod(value) || v->back()->getType() != type)
	    throw DifferentValueException();
}

const char* Assert::DifferentValueException::what() const noexcept
{
	return ("Exception: Different value or type !");
}
