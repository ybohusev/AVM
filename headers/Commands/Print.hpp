/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Print.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:09:15 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:09:18 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_PRINT_HPP
#define ABSTRACTVM_PRINT_HPP

#include "Commands.hpp"

class Print : public Commands
{
public:
    ~Print();
	void doCommands(std::vector<IOperand const *> *v);

	class NotEightTypeException : public std::exception
	{
	public:
		virtual const char *what() const noexcept;
	};
};

#endif
