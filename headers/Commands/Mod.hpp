/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mod.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:42 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:47 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_MOD_HPP
#define ABSTRACTVM_MOD_HPP

#include "Commands.hpp"

class Mod : public Commands
{
public:
    ~Mod();
	void doCommands(std::vector<IOperand const *> *v);
};

#endif
