/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:52:34 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/02 19:23:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

void	print_array_int(Array<int>& array)
{
	unsigned int i;

	i = 0;
	while (i < array.size())
	{
		std::cout << i << ":\t" << BLUE << array[i] << RESET << std::endl;
		i++;
	}
}

void	print_array_char(Array<char>& array)
{
	unsigned int i;

	i = 0;
	while (i < array.size())
	{
		std::cout << i << ":\t" << BLUE << array[i] << RESET << std::endl;
		i++;
	}
}

int main(void)
{
	Array<int>	tab_int(5);
	Array<int>	tab_cpy(tab_int);
	Array<int>	tab_operator(5);

	unsigned int i;

	i = -1;
	while (++i < 5)
		tab_int[i] = i + 1;
	tab_operator = tab_int;
	std::cout << GREY << "-------------Initial Arrays int----------------" << RESET << std::endl;
	std::cout << GREEN << "tab_int:" << RESET << std::endl;
	print_array_int(tab_int);
	std::cout << GREEN << "\ntab_cpy:" << RESET << std::endl;
	print_array_int(tab_cpy);
	std::cout << GREEN << "\ntab_operator:" << RESET << std::endl;
	print_array_int(tab_operator);
	std::cout << std::endl;

	std::cout << GREY << "[Multiply by 2 tab_int]" << RESET << std::endl;
	i = -1;
	while (++i < tab_int.size())
		tab_int[i] *= 2;
	std::cout << std::endl;

	std::cout << GREY << "-----------Arrays after modification:------------" << RESET << std::endl;
	std::cout << GREEN << "tab_int:" << RESET << std::endl;
	print_array_int(tab_int);
	std::cout << GREEN << "\ntab_cpy:" << RESET << std::endl;
	print_array_int(tab_cpy);
	std::cout << GREEN << "\ntab_operator:" << RESET << std::endl;
	print_array_int(tab_operator);
	std::cout << std::endl;

}