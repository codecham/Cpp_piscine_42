/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:43:12 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 20:11:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ft_print_error_file(std::string file_name)
{
	std::cout << "ERROR:" << std::endl;
	std::cout << file_name << "can't be open" << std::endl;
	exit(0);
}

void	ft_print_error_param()
{
	std::cout << "WRONG NUMBER OF PARAMETER\n" << std::endl;
	std::cout << "USAGE:" << std::endl;
	std::cout << "./replace [FILE] [STRING_1] [STRING_2]" << std::endl;
	exit(0);
}

void	ft_check_arg(std::string file, std::string s1, std::string s2)
{
	if (file.empty() || s1.empty() || s2.empty())
	{
		std::cout << "ERROR:" << std::endl;
		std::cout << "PARAMETERS CAN'T BE EMPTY" << std::endl;
		exit(0);
	}
}
