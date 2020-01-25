/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:03:21 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:03:22 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Sub.hpp"

Sub::Sub()
{
}

Sub::Sub(Sub const &obj)
{
	*this = obj;
}

Sub& Sub::operator=(Sub const &obj)
{
	(void)obj;
	return *this;
}

Sub::~Sub()
{
}

void Sub::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() < 2)
		throw Commands::FewArgumentsException();
	IOperand const *num1 = v->back();
	v->pop_back();
	IOperand const *num2 = v->back();
	v->pop_back();
	v->push_back((*num1) - (*num2));
	(void)line;
}
