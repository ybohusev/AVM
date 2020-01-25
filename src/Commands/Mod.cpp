/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mod.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:01:57 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:02:01 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Mod.hpp"

Mod::Mod()
{
}

Mod::Mod(Mod const &obj)
{
	*this = obj;
}

Mod& Mod::operator=(Mod const &obj)
{
	(void)obj;
	return *this;
}

Mod::~Mod()
{
}

void Mod::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() < 2)
		throw Commands::FewArgumentsException();
	IOperand const *num1 = v->back();
	v->pop_back();
	IOperand const *num2 = v->back();
	v->pop_back();
	v->push_back((*num2) % (*num1));
	(void)line;
}
