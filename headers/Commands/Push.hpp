/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:26 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:09:30 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_PUSH_HPP
#define ABSTRACTVM_PUSH_HPP

#include "Commands.hpp"

class Push : public Commands
{

    std::string value;
    eOperandType type;
public:
	Push();
	Push(Push const &obj);
    Push(const std::string& value_, eOperandType type_);
	~Push();
	Push &operator=(Push const &obj);
	void doCommands(std::vector<IOperand const *> *v);
};

#endif
