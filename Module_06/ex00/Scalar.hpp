/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:08:58 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/08 21:19:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <math.h>
#include <limits.h>
#include <cctype>
#include <iomanip>

class Scalar
{
	public:
		Scalar();
		Scalar(const char *arg);
		Scalar(const Scalar& copy);
		~Scalar(void);
		Scalar& operator=(const Scalar& copy);

		void	printAll();
		void	convert(const char *str);

	private:
		char	_ch_value;
		int		_int_value;
		float	_fl_value;
		double	_db_value;
		bool	_impossible_int;
		bool	_impossible_ch;
		bool	_all_impossible;
		void	detectType(const char *arg);
		bool	pseudo_float(std::string str);
		bool	pseudo_double(std::string str);
		void	change_to_inf(bool is_neg);
		bool	isChar(const char *str);
		bool	isInt(const char *str);
		bool	isFloat(const char *str);
		bool	isDouble(const char *str);
		bool	isPseudoLitteral(const char *str);
		void	printChar();
		void	printInt();
		void	printFloat();
		void	printDouble();
};

#endif