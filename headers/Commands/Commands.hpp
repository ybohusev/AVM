/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:08:09 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:08:16 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "../IOperand.hpp"
#include "../OFactory.hpp"
#include <vector>
#include <sstream>


class Commands
{
public:
	std::vector<std::string> nameType;

	Commands();
	void initNameType();
	virtual ~Commands();
	virtual void doCommands(std::vector<IOperand const *> *v, std::string line) = 0;

	class WrongTypeException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class WrongValueException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class FewArgumentsException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class EmpyStackException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};
};

#endif
