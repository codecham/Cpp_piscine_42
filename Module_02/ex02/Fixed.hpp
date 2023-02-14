/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:26:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/08 23:38:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int int_num);
		Fixed(const float float_num);
		Fixed(const Fixed& copy);
		~Fixed(void);
		
		Fixed& operator=(const Fixed& copy);
		bool	operator>(const Fixed& second_fixed) const;
		bool	operator<(const Fixed& second_fixed) const;
		bool	operator>=(const Fixed& second_fixed) const;
		bool	operator<=(const Fixed& second_fixed) const;
		bool	operator==(const Fixed& second_fixed) const;
		bool	operator!=(const Fixed& second_fixed) const;
		Fixed	operator+(const Fixed& second_fixed) const;
		Fixed	operator-(const Fixed& second_fixed) const;
		Fixed	operator*(const Fixed& second_fixed) const;
		Fixed	operator/(const Fixed& second_fixed) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& first_fixed, Fixed& second_fixed);
		static const Fixed&	min(const Fixed& first_fixed, const Fixed& second_fixed);
		static Fixed&		max(Fixed& first_fixed, Fixed& second_fixed);
		static const Fixed&	max(const Fixed& first_fixed, const Fixed& second_fixed);
		int 				getRawBits(void) const ;
		void 				setRawBits(int const raw);
		float 				toFloat(void) const;
		int					toInt() const;

				
	private:
		int					_raw_bits;
		static const int 	_fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif