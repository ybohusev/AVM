/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dump.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:33 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:36 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_DUMP_HPP
#define ABSTRACTVM_DUMP_HPP

#include "Commands.hpp"

class Dump : public Commands
{
public:
	Dump();
	Dump(Dump const &obj);
	~Dump();
	Dump &operator=(Dump const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};
#endif
