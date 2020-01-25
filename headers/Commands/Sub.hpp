/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sub.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:37 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:09:40 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_SUB_HPP
#define ABSTRACTVM_SUB_HPP

#include "Commands.hpp"

class Sub : public Commands
{
public:
	Sub();
	Sub(Sub const &obj);
	~Sub();
	Sub &operator=(Sub const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
};
#endif
