/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:01:18 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:01:24 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/Commands/Commands.hpp"

Commands::~Commands()
{
}
const char* Commands::WrongTypeException::what() const noexcept
{
	return ("Exception: Wrong type !");
}

const char* Commands::FewArgumentsException::what() const noexcept
{
	return ("Exception: Too few arguments !");
}

const char* Commands::EmpyStackException::what() const noexcept
{
	return ("Exception: Empty stack !");
}

const char* Commands::WrongValueException::what() const noexcept
{
	return ("Exception: Wrong value !");
}
