/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:01:33 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:01:37 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Div.hpp"

Div::Div()
{
}

Div::Div(Div const &obj)
{
	*this = obj;
}

Div& Div::operator=(Div const &obj)
{
	(void)obj;
	return *this;
}

Div::~Div()
{
}

void Div::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() < 2)
		throw Commands::FewArgumentsException();
	IOperand const *num1 = v->back();
	v->pop_back();
	IOperand const *num2 = v->back();
	v->pop_back();
	v->push_back((*num2) / (*num1));
	(void)line;
}
