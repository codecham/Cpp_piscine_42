/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:53:05 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/03 02:46:24 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

void	vectorTest()
{
	std::vector<int> vec;
	std::vector<int>::iterator it;
	
	int i;

	i = 0;
	while (i < 10)
	{
		vec.push_back((i + 1) * 4);
		i++;
	}
	std::cout << "Find 12 in int vector:" << std::endl;
	it = easyfind(vec, 13);
	std::cout << *it << std::endl;
}

void	dequeTest()
{
	
}

void	listTest()
{
	
}

int main()
{
	vectorTest();
	
}