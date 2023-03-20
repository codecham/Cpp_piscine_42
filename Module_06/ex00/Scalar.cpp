/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 09:36:46 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/08 21:18:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int _int_value;

Scalar::Scalar()
{
	_all_impossible = true;
}

Scalar::Scalar(const char *arg)
{
	_impossible_ch = false;
	_impossible_int = false;
	_all_impossible = false;
	detectType(arg);
	if (_db_value < INT_MIN || _db_value > INT_MAX || isnan(_db_value))
	{
		_impossible_int = true;
		_impossible_ch = true;
	}
	else if (_db_value < CHAR_MIN || _db_value > CHAR_MAX)
		_impossible_ch = true;
}

Scalar::Scalar(const Scalar& copy)
{
	*this = copy;
}

Scalar::~Scalar(void)
{

}

Scalar&	Scalar::operator=(const Scalar& copy)
{
	this->_ch_value = copy._ch_value;
	_int_value = copy._int_value;
	_fl_value = copy._fl_value;
	_db_value = copy._db_value;
	_impossible_int = copy._impossible_int;
	_impossible_ch = copy._impossible_ch;
	_all_impossible = copy._all_impossible;
	return(*this);
}

void	Scalar::convert(const char *str)
{
	_impossible_ch = false;
	_impossible_int = false;
	_all_impossible = false;
	detectType(str);
	if (_db_value < INT_MIN || _db_value > INT_MAX || isnan(_db_value))
	{
		_impossible_int = true;
		_impossible_ch = true;
	}
	else if (_db_value < CHAR_MIN || _db_value > CHAR_MAX)
		_impossible_ch = true;

}

void	Scalar::printChar()
{
	std::cout << "char: ";
	if (_all_impossible || _impossible_ch)
		std::cout << "impossible" << std::endl;
	else if (_ch_value < 32 || _ch_value > 127)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" <<  _ch_value << "'" << std::endl;
}

void	Scalar::printInt()
{
	std::cout << "int: ";
	if (_all_impossible || _impossible_int)
		std::cout << "impossible" << std::endl;
	else
		std::cout << _int_value << std::endl;
}

void	Scalar::printFloat()
{
	std::cout << "float: ";
	if (_all_impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		if(_fl_value == std::numeric_limits<float>::infinity())
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_fl_value) << "f" << std::endl;
	}
}

void	Scalar::printDouble()
{
	std::cout << "double: ";
	if (_all_impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		if (_fl_value == std::numeric_limits<float>::infinity())
			std::cout << "+";
		std::cout << std::fixed << std::setprecision(1) << _db_value << std::endl;
	}
}

void	Scalar::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void	Scalar::detectType(const char *arg)
{
	if (isChar(arg))
		return ;
	if (isInt(arg))
		return;
	if (isPseudoLitteral(arg))
		return ;
	if (isFloat(arg))
		return ;
	if (isDouble(arg))
		return ;
	_all_impossible = true;
}

bool	Scalar::isChar(const char *str)
{
	if (str[0] && !str[1] && !isdigit(str[0]))
	{
		_ch_value = str[0];
		_int_value = static_cast<int>(str[0]);
		_fl_value = static_cast<float>(str[0]);
		_db_value = static_cast<double>(str[0]);
		return (true);
	}
	return(false);
}

bool	Scalar::isInt(const char *str)
{
	long value;
	char *endptr;

	value = strtol(str, &endptr, 10);
	if (!(*endptr) && (value >= INT_MIN && value <= INT_MAX))
	{
		_int_value = static_cast<int>(value);
		_fl_value = static_cast<float>(value);
		_db_value = static_cast<double>(value);
		this->_ch_value = static_cast<char>(value);
		return (true);
	}
	return (false);
}

bool	Scalar::isFloat(const char *str)
{
	long value;
	char *endptr;

	value = strtof(str, &endptr);
	if ((*endptr) == 'f')
	{
		_fl_value = value;
		_int_value = static_cast<int>(value);
		_db_value = static_cast<double>(value);
		this->_ch_value = static_cast<char>(value);
		return(true);
	}
	return(false);
}

bool	Scalar::isDouble(const char *str)
{
	long value;
	char *endptr;

	value = strtod(str, &endptr);
	if (!(*endptr))
	{
		_db_value = value;
		_int_value = static_cast<int>(value);
		_fl_value = static_cast<float>(value);
		this->_ch_value = static_cast<char>(value);
		return(true);
	}
	return(false);
}

bool	Scalar::isPseudoLitteral(const char *str)
{
	if (pseudo_float(str))
	{
		return(true);
	}
	else if (pseudo_double(str))
	{
		return(true);
	}
	return(false);
}

bool	Scalar::pseudo_float(std::string str)
{
	if (str == "+inff")
	{
		change_to_inf(false);
		return(true);
	}
	else if (str == "-inff")
	{
		change_to_inf(true);
		return(true);
	}
	else if (str == "nanf")
	{
		_impossible_int = false;
		_fl_value = NAN;
		_db_value = NAN;
		return(true);
	}
	return(false);
}

bool	Scalar::pseudo_double(std::string str)
{
	if (str == "+inf")
	{
		change_to_inf(false);
		return(true);
	}
	else if (str == "-inf")
	{
		change_to_inf(true);
		return(true);
	}
	else if (str == "nan")
	{
		_impossible_int = false;
		_fl_value = NAN;
		_db_value = NAN;
		return(true);
	}
	return(false);
}

void	Scalar::change_to_inf(bool is_neg)
{
	_fl_value = std::numeric_limits<float>::infinity();
	_db_value = std::numeric_limits<double>::infinity();
	if (is_neg)
	{
		_fl_value *= -1;
		_db_value *= -1;
	}
}