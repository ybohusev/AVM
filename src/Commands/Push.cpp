/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:03:13 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:03:15 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Push.hpp"

Push::~Push()
{
}

Push::Push()
{
    type = UNKNOWN;
    value = std::string();
}

Push::Push(Push const &obj)
{
	*this = obj;
}

Push& Push::operator=(Push const &obj)
{
    if (this == &obj)
        return  *this;
	this->value = obj.value;
	this->type = obj.type;
	return *this;
}

Push::Push(const std::string& value_, eOperandType type_)
{
    value = value_;
    type = type_;
}

void Push::doCommands(std::vector<IOperand const *> *v)
{
	OFactory fact;
	v->push_back(fact.createOperand(type, value));
}
