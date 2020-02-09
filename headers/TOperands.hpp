/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TOperands.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:06:48 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:06:52 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_TOPERANDS_HPP
# define ABSTRACTVM_TOPERANDS_HPP
# include <cmath>
# include <iomanip>
# include "IOperand.hpp"
#include "OFactory.hpp"
class OFactory;

template <typename T>
class TOperands : public IOperand
{

private:
	eOperandType _type;
	T _value;
	OFactory *fact;
	std::string const *str;


public:

	class OverflowValue : public std::out_of_range
	{
	public:
		OverflowValue(std::string const& msg) : std::out_of_range(msg) { }
		~OverflowValue() throw(){}
	};

	class UnderflowValue : public std::out_of_range
	{
	public:
		UnderflowValue(std::string const& msg) : std::out_of_range(msg) { }
		~UnderflowValue() throw(){}
	};

	class DivisionZero : public std::exception
	{
	public:
		DivisionZero(){}
		DivisionZero(DivisionZero const &obj)
		{
			*this = obj;
		}
		~DivisionZero() throw(){}
		DivisionZero &operator=(DivisionZero const &obj)
		{
			(void)obj;
			return *this;
		}
		virtual const char *what() const throw()
		{
			return "Division or modulo by 0 !";
		}
	};

	TOperands() : _type(Int8),  _value(0), fact(NULL)
	{
	}

	virtual ~TOperands(void)
	{
		delete str;
	}

	TOperands(eOperandType type, T value) : _type(type), _value(value), fact(NULL)
	{
		str = new std::string(std::to_string(_value));
	}

	TOperands &operator=(TOperands const &obj)
	{
		_type = obj._type;
		_value = obj._value;
		return *this;
	}

	int getPrecision(void) const
	{
			return _type;
	}

	eOperandType getType(void) const
	{
		return _type;
	}

	OFactory *retByPointer() const
	{
		return fact;
	}

	IOperand const *operator+(IOperand const &rhs) const
	{
		IOperand const *o = NULL;
		eOperandType newType = _type;
		std::string value;

		newType = _type < rhs.getType() ? rhs.getType() : _type;
		value = std::to_string((std::stod(this->toString()) + std::stod(rhs.toString())));
		o = retByPointer()->createOperand(newType, value);
		return o;
	}

	IOperand const *operator-(IOperand const &rhs) const
	{
		IOperand const *o;
		eOperandType newType = _type;
		std::string value;

		newType = _type < rhs.getType() ? rhs.getType() : _type;
		value = std::to_string((std::stod(this->toString()) - std::stod(rhs.toString())));
		o = retByPointer()->createOperand(newType, value);
		return o;
	}

	IOperand const *operator*(IOperand const &rhs) const
	{
		IOperand const *o;
		eOperandType newType = _type;
		std::string value;

		newType = _type < rhs.getType() ? rhs.getType() : _type;
		value = std::to_string((std::stod(this->toString()) * std::stod(rhs.toString())));
		o = retByPointer()->createOperand(newType, value);
		return o;
	}

	IOperand const *operator/(IOperand const &rhs) const
	{
		IOperand const *o;
		eOperandType newType = _type;
		std::string value;

		newType = _type < rhs.getType() ? rhs.getType() : _type;
		if (std::stod(rhs.toString()) == 0)
			throw DivisionZero();
		value = std::to_string((std::stod(this->toString()) / std::stod(rhs.toString())));
		o = retByPointer()->createOperand(newType, value);
		return o;
	}

	IOperand const *operator%(IOperand const &rhs) const
	{
		IOperand const *o;
		eOperandType newType = _type;
		std::string value;

		newType = _type < rhs.getType() ? rhs.getType() : _type;
		if (std::stod(rhs.toString()) == 0)
			throw DivisionZero();
		value = std::to_string(std::fmod(std::stod(this->toString()), std::stod(rhs.toString())));
		o = retByPointer()->createOperand(newType, value);
		return o;
	}

	std::string const &toString(void) const
	{
		//std::string const *str = new std::string(std::to_string(_value));
		return *str;
	}

};

#endif
