/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:25:45 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/23 00:56:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

int	ft_is_digit(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	Contact::ft_set_first_name()
{
	std::string input;
	
	this->first_name = input;
}

void	Contact::ft_set_last_name()
{
	std::string input;

	this->last_name = input;
}

void	Contact::ft_set_nickname()
{
	std::string input;
	
	this->last_name = input;
}

void	Contact::ft_set_phone_number()
{
	int			i;
	std::string input;

	i = 0;
	while (1)
	{
		std::cout << "Enter your phone number: ";
  		std::getline(std::cin, input);
		if (ft_is_digit(input) == 0)
			break ;
		else
			std::cout << "Phone number can only has digit!" << std::endl;
	}
	this->phone_number = input;
}