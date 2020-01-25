/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mul.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:54 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:58 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_MUL_HPP
#define ABSTRACTVM_MUL_HPP

#include "Commands.hpp"

class Mul : public Commands
{
public:
	Mul();
	Mul(Mul const &obj);
	~Mul();
	Mul &operator=(Mul const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};

#endif
