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

Dump::~Dump()
{
}

void Dump::doCommands(std::vector<IOperand const *> *v)
{
	if (v->empty())
		throw Commands::EmpyStackException();
	for (auto it = v->rbegin(); it < v->rend(); ++it)
		std::cout << (*it)->toString() << std::endl;
}
