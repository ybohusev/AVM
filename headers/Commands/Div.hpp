/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Div.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:23 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:26 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_DIV_HPP
#define ABSTRACTVM_DIV_HPP

#include "Commands.hpp"

class Div : public Commands
{
public:
	Div();
	Div(Div const &obj);
	~Div();
	Div &operator=(Div const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};

#endif
