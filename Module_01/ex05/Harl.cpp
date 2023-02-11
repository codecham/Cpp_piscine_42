/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:15:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 21:16:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	
}

void	Harl::complain(std::string complain)
{
	void (Harl::*ft_ptr[4])(void);
	std::string	levels[4];
	int i;

	ft_ptr[0] = &Harl::debug;
	ft_ptr[1] = &Harl::info;
	ft_ptr[2] = &Harl::warning;
	ft_ptr[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	i = 0;
	while (levels[i] != complain)
	{
		i++;
		if (i > 3)
			return ;
	}
	(this->*ft_ptr[i])();
}

void	Harl::debug()
{
	std::cout << "\033[1;32m" << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << "\033[0m" << std::endl;
}

void	Harl::info()
{
	std::cout << "\033[1;34m" << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger ! If you did, I wouldn’t be asking for more !" << "\033[0m" << std::endl;
}

void	Harl::warning()
{
	std::cout << "\033[1;33m" << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been comingfor years whereas you started working here since last month." << "\033[0m" << std::endl;
}

void	Harl::error()
{
	std::cout << "\033[1;31m" << "[ERROR] This is unacceptable ! I want to speak to the manager now" << "\033[0m" << std::endl;
}