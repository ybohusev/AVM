/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Assert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:00 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_ASSERT_HPP
#define ABSTRACTVM_ASSERT_HPP

#include "Commands.hpp"

class Assert : public Commands
{
public:
	Assert();
	Assert(Assert const &obj);
	~Assert();
	Assert &operator=(Assert const &obj);
	void doCommands(std::vector<IOperand const *> *v, std::string line);
	class DifferentValueException : public std::exception
	{
	public:
		DifferentValueException();
		DifferentValueException(DifferentValueException const &obj);
		~DifferentValueException() throw();
		DifferentValueException &operator=(DifferentValueException const &obj);
		virtual const char *what() const throw();
	};
};


#endif
