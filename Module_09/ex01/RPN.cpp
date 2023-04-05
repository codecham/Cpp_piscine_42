/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:48:12 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/06 00:33:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& copy)
{
	_stack = copy._stack;
}

RPN::~RPN(void)
{

}

RPN&	RPN::operator=(const RPN& copy)
{
	if (this != &copy)
		_stack = copy._stack;
	return (*this);
}

bool		RPN::isDigit(char c) const
{
	if (c >= '0' && c <= '9')
		return(true);
	return(false);
}

bool		RPN::isOp(char c) const
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return(true);
	return(false);
}

void		RPN::erase_stack()
{
	while (!_stack.empty())
		_stack.pop();
}

void	RPN::run(std::string str)
{
	unsigned int i;

	i = 0;
	while(i < str.size())
	{
		if (isDigit(str[i]))
			_stack.push(str[i] - '0');
		else if (isOp(str[i]))
		{
			if (doOp(str[i]) == false)
			{
				erase_stack();
				return ;
			}
		}
		else
		{
			std::cout << "Wrong caracter at [ " << str[i] << "] at index " << i << std::endl;
			erase_stack();
			return ;
		}
		i++;
		if (str[i] && str[i] != ' ')
		{
			std::cout << "Wrong caracter at [ " << str[i] << "] at index " << i << std::endl;
			erase_stack();
			return ;
		}
		i++;
	}
	if (_stack.size() != 1)
	{
		std::cout << "Impossible stack no empty" << std::endl;
		return ;
	}
	std::cout << _stack.top() << std::endl;
	erase_stack();
}

bool	RPN::doOp(char op)
{
	float a;
	float b;

	if (_stack.size() < 2)
	{
		std::cout << "Impossible" << std::endl;
		return(false);
	}
	b = _stack.top();
	_stack.pop();
	a = _stack.top();
	_stack.pop();
	if (op == '+')
		_stack.push(a + b);
	else if (op == '-')
		_stack.push(a - b);
	else if (op == '*')
		_stack.push(a * b);
	else
	{
		if (b == 0)
		{
			std::cout << "Division by 0 impossible" << std::endl;
			return(false);
		}
		_stack.push(a / b);
	}
	return(true);
}