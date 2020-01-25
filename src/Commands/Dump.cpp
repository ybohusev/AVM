/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:01:47 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:01:50 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Dump.hpp"

Dump::Dump()
{
}

Dump::Dump(Dump const &obj)
{
	*this = obj;
}

Dump& Dump::operator=(Dump const &obj)
{
	(void)obj;
	return *this;
}

Dump::~Dump()
{
}

void Dump::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() == 0)
		throw Commands::EmpyStackException();
	for (int i = v->size() - 1; i >= 0; i--)
		std::cout << v->at(i)->toString() << std::endl;
	(void)line;
}
