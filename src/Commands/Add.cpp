/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:00:54 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:00:59 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Add.hpp"

Add::Add()
{
}

Add::Add(Add const &obj)
{
	*this = obj;
}

Add& Add::operator=(Add const &obj)
{
	(void)obj;
	return *this;
}

Add::~Add()
{
}

void Add::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() < 2)
		throw Commands::FewArgumentsException();
	IOperand const *num1 = v->back();
	v->pop_back();
	IOperand const *num2 = v->back();
	v->pop_back();
	v->push_back((*num2) + (*num1));
	(void)line;
}
