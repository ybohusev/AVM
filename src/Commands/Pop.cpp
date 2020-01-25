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

Pop::Pop()
{
}

Pop::Pop(Pop const &obj)
{
	*this = obj;
}

Pop& Pop::operator=(Pop const &obj)
{
	(void)obj;
	return *this;
}

Pop::~Pop()
{
}

void Pop::doCommands(std::vector<IOperand const *> *v, std::string line)
{
	if (v->size() == 0)
		throw Commands::EmpyStackException();
	v->pop_back();
	(void)line;
}
