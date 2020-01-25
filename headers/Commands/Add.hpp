/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:07:50 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:07:54 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_ADD_HPP
#define ABSTRACTVM_ADD_HPP

#include "Commands.hpp"

class Add : public Commands
{
public:
	Add();
	~Add();
	Add(Add const &obj);
	Add &operator=(Add const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};

#endif
