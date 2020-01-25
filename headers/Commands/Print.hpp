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
	Print();
	Print(Print const &obj);
	~Print();
	Print &operator=(Print const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);

	class NotEightTypeException : public std::exception
	{
	public:
		NotEightTypeException();
		NotEightTypeException(NotEightTypeException const &obj);
		~NotEightTypeException() throw();
		NotEightTypeException &operator=(NotEightTypeException const &obj);
		virtual const char *what() const throw();
	};
};

#endif
