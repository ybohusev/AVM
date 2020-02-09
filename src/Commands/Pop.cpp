/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:02:53 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:02:55 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Pop.hpp"

Pop::~Pop()
{
}

void Pop::doCommands(std::vector<IOperand const *> *v)
{
	if (v->empty())
		throw Commands::EmpyStackException();
	IOperand const *tmp = v->back();
	v->pop_back();
	delete tmp;
}
