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
public:
	Push();
	Push(Push const &obj);
	~Push();
	Push &operator=(Push const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};

#endif
