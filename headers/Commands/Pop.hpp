/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pop.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:05 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:09:09 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_POP_HPP
#define ABSTRACTVM_POP_HPP

#include "Commands.hpp"

class Pop : public Commands
{
public:
	Pop();
	Pop(Pop const &obj);
	~Pop();
	Pop &operator=(Pop const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};

#endif
