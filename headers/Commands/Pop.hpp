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
    ~Pop();
	void doCommands(std::vector<IOperand const *> *v);
};

#endif
