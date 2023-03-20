/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:08:03 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/20 19:44:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>
#include <algorithm>

RPN::RPN()
{
	_index = 0;
	_result = 0;
}

RPN::RPN(const RPN& copy)
{
	_index = copy._index;
	_result = copy._result;
	_value = copy._value;
	_op = copy._op;
}

RPN::~RPN(void)
{

}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
	{
		_index = copy._index;
		_result = 0;
		_value = copy._value;
		_op = copy._op;
	}
	return(*this);
}

bool	RPN::run(char *str)
{
	int i;
	int tmp;

	i = 0;
	_value.clear();
	_op.clear();
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return(false);
	if (addOperation(str[i], '\0') == false)
		return(false);
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			tmp = subOperation(&str[i]);
			if (tmp < 0)
				return (false);
			i += tmp ;
			i++;
		}
	}
	doOperations();
	printResult();
	return(true);
}

int RPN::subOperation(char *str)
{
	int i;

	i = 1;
	if (!str[1])
		return (-3);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (!str[i])
			return (-2);
		if (addOperation(str[0], str[i]) == false)
			return (-1);
		else
			break ;
	}
	return(i);
}

bool	RPN::checkValues(char value, char op)
{
	if (value < '0' || value > '9')
		return (false);
	if (op)
	{
		if (op != '+' && op != '-' && op != '*' && op != '/')
			return (false);
	}
	return (true);
}

bool	RPN::addOperation(char value, char op)
{
	const int i = _index;
	std::map<int, int>::iterator it_value;
	std::map<int, char>::iterator it_op;
	
	it_value = _value.end();
	it_op = _op.end();
	if (checkValues(value, op))
	{
		_value.insert(it_value, std::pair<int, int>(i, (value - '0')));
		if (op)
			_op.insert(it_op, std::pair<int, char>(i, op));
		else
			_op.insert(it_op, std::pair<int, char>(i, 'n'));
		_index++;
		return(true);
	}
	return(false);
}

char RPN::getOp(const int index)
{
	return (_op[index]);
}

int	RPN::getValue(const int index)
{
	return (_value[index]);
}

void	RPN::doOperations()
{
	int i;
	int value;
	char op;

	i = 1;
	_result = _value[0];
	while (i < _index)
	{
		value = getValue(i);
		op = getOp(i);
		if (op == '+')
			_result += value;
		else if (op == '-')
			_result -= value;
		else if (op == '/')
			_result /= value;
		else if (op == '*')
			_result *= value;
		i++;
	}
}

void	RPN::printResult() const
{
	std::cout << _result << std::endl; 
}