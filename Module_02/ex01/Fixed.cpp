/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:06:26 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/08 00:53:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_raw_bits = 0;
}

Fixed::Fixed(const int int_num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw_bits = int_num << this->_fractional_bits;
}

Fixed::Fixed(const float float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw_bits = roundf(float_num * (1 << this->_fractional_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_raw_bits = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw_bits = raw;
}

float Fixed::toFloat() const
{
	return((float)(this->_raw_bits / (float)(1 << this->_fractional_bits)));

}

int Fixed::toInt() const
{
	return (this->_raw_bits >> this->_fractional_bits);
}

int const		Fixed::_fractional_bits = 8;