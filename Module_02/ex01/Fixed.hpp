/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:26:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/08 00:52:31 by dcorenti         ###   ########.fr       */
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

		int 	getRawBits(void) const ;
		void 	setRawBits(int const raw);
		float 	toFloat(void) const;
		int		toInt() const;

				
	private:
		int					_raw_bits;
		static const int 	_fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif