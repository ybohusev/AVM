/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OFactory.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:06:23 by ybohusev          #+#    #+#             */
/*   Updated: 2020/01/25 16:06:28 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACTVM_OFACTORY_HPP
# define ABSTRACTVM_OFACTORY_HPP

# include "IOperand.hpp"
# include "TOperands.hpp"
# include <limits>
# include <cfloat>

class OFactory
{
private:
	IOperand const *createInt8(std::string const &value) const;
	IOperand const *createInt16(std::string const &value) const;
	IOperand const *createInt32(std::string const &value) const;
	IOperand const *createFloat(std::string const &value) const;
	IOperand const *createDouble(std::string const &value) const;

public:
	OFactory();
	OFactory(OFactory const &obj);
	~OFactory();
	OFactory &operator=(OFactory const &obj);
	IOperand const *createOperand(eOperandType type, std::string const &value) const;
};

#endif
