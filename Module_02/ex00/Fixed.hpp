/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:26:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/08 00:34:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed(void);
		Fixed& operator=(const Fixed& copy);

		int 	getRawBits(void) const ;
		void 	setRawBits(int const raw);

	private:
		int					_raw_bits;
		static const int 	_fractional_bits;
};

#endif