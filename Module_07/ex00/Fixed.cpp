/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:06:26 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 09:32:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
** ----------------------Constructors & Destructor------------------------------
*/

Fixed::Fixed()
{
	this->_raw_bits = 0;
}

Fixed::Fixed(const int int_num)
{
	this->_raw_bits = int_num << this->_fractional_bits;
}

Fixed::Fixed(const float float_num)
{
	this->_raw_bits = roundf(float_num * (1 << this->_fractional_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed::~Fixed()
{

}



/*
** ----------------------------Operators--------------------------------------
*/

Fixed& 	Fixed::operator=(const Fixed& copy)
{
	if (this != &copy)
		this->_raw_bits = copy.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed& second_fixed) const
{
	if (this->toFloat() > second_fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed& second_fixed) const
{
	if (this->toFloat() < second_fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& second_fixed) const
{
	if (this->toFloat() >= second_fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& second_fixed) const
{
	if (this->toFloat() <= second_fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed& second_fixed) const
{
	if (this->toFloat() == second_fixed.toFloat())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& second_fixed) const
{
	if (this->toFloat() != second_fixed.toFloat())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed& second_fixed) const
{
	return(this->toFloat() + second_fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed& second_fixed) const
{
	return(this->toFloat() - second_fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed& second_fixed) const
{
	return(this->toFloat() * second_fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed& second_fixed) const
{
	return(this->toFloat() / second_fixed.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->_raw_bits++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	this->_raw_bits++;
	return(tmp);
}

Fixed&	Fixed::operator--()
{
	this->_raw_bits++;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	this->_raw_bits--;
	return(tmp);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}

/*
** ----------------------------Member Functions-------------------------------
*/

int Fixed::getRawBits() const
{
	return (this->_raw_bits);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed&		Fixed::min(Fixed& first_fixed, Fixed& second_fixed)
{
	if (first_fixed < second_fixed)
		return(first_fixed);
	return(second_fixed);
}

const Fixed&	Fixed::min(const Fixed& first_fixed, const Fixed& second_fixed)
{
	if (first_fixed < second_fixed)
		return(first_fixed);
	return(second_fixed);
}


Fixed&		Fixed::max(Fixed& first_fixed, Fixed& second_fixed)
{
	if (first_fixed > second_fixed)
		return(first_fixed);
	return(second_fixed);
}

const Fixed&	Fixed::max(const Fixed& first_fixed, const Fixed& second_fixed)
{
	if (first_fixed > second_fixed)
		return(first_fixed);
	return(second_fixed);	
}

/*
** ----------------------------Extern Functions--------------------------------
*/


int const		Fixed::_fractional_bits = 8;