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
    eOperandType type;
    std::string value;
public:
	Assert();
	Assert(const std::string& value_, eOperandType type_);
	Assert(Assert const &obj);
	~Assert();
	Assert &operator=(Assert const &obj);
	void doCommands(std::vector<IOperand const *> *v);

	class DifferentValueException : public std::exception
	{
	public:
        const char *what() const noexcept override;
	};
};


#endif
