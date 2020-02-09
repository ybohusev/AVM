/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:02:13 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:02:14 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Mul.hpp"

Mul::~Mul()
{
}

void Mul::doCommands(std::vector<IOperand const *> *v)
{
	if (v->size() < 2)
		throw Commands::FewArgumentsException();
	IOperand const *num1 = v->back();
	v->pop_back();
	IOperand const *num2 = v->back();
	v->pop_back();
	v->push_back((*num2) * (*num1));
    delete num1;
    delete num2;
}
