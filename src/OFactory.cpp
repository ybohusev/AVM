/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OFactory.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:58:51 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 15:59:06 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/OFactory.hpp"

OFactory::OFactory()
{
}

OFactory::OFactory(OFactory const &obj)
{
	*this = obj;
}

OFactory::~OFactory()
{
}

OFactory& OFactory::operator=(OFactory const &obj)
{
	(void)obj;
	return *this;
}

IOperand const *OFactory::createInt8(std::string const &value) const
{
	IOperand *o = NULL;
	int val = 0;

	val = std::stoi(value);
	if (val > INT8_MAX)
		throw TOperands<int8_t>::OverflowValue("Overflow on a value !");
	else if (val < INT8_MIN)
		throw TOperands<int8_t>::UnderflowValue("Underflow on a value !");
	o = new TOperands<int8_t >(Int8, val);
	return o;
}

IOperand const *OFactory::createInt16(std::string const &value) const
{
	IOperand *o = NULL;
	int val = 0;

	val = std::stoi(value);
	if (val > INT16_MAX)
		throw TOperands<int16_t>::OverflowValue("Overflow on a value !");
	else if (val < INT16_MIN)
		throw TOperands<int16_t>::UnderflowValue("Underflow on a value !");
	o = new TOperands<int16_t>(Int16, val);
	return o;
}

IOperand const *OFactory::createInt32(std::string const &value) const
{
	IOperand *o = NULL;
	double val = 0;

	val = std::stod(value);
	if (val > INT32_MAX)
		throw TOperands<int32_t>::OverflowValue("Overflow on a value !");
	else if (val < INT32_MIN)
		throw TOperands<int32_t>::UnderflowValue("Underflow on a value !");
	o = new TOperands<int32_t>(Int32, std::stoi(value));
	return o;
}

IOperand const *OFactory::createFloat(std::string const &value) const
{
	IOperand *o = NULL;
	double val = 0;

	val = std::stod(value);
	if (val > FLT_MAX)
		throw TOperands<float>::OverflowValue("Overflow on a value !");
	else if (val < -FLT_MAX)
		throw TOperands<float>::UnderflowValue("Underflow on a value !");
	o = new TOperands<float>(Float, std::stof(value));
	return o;
}

IOperand const *OFactory::createDouble(std::string const &value) const
{
	IOperand *o = NULL;
	double val = 0;

	val = std::stod(value);
	if (val > DBL_MAX)
		throw TOperands<double>::OverflowValue("Overflow on a value !");
	else if (val < -DBL_MAX)
		throw TOperands<double>::UnderflowValue("Underflow on a value !");
	o = new TOperands<double>(Double, val);
	return o;
}

IOperand const *OFactory::createOperand(eOperandType type, std::string const &value) const
{
	IOperand const *o = NULL;
	IOperand const *(OFactory::*fnPtr[5])(std::string const &value) const = {&OFactory::createInt8,
	 															&OFactory::createInt16,
	 															&OFactory::createInt32,
	 															&OFactory::createFloat,
	 															&OFactory::createDouble};

	o = dynamic_cast<const IOperand *>((this->*(fnPtr[type]))(value));
	return o;
}
