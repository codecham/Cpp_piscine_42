/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:53:05 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/29 19:04:39 by dcorenti         ###   ########.fr       */
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
	
	/*--------------fill vector---------------*/
	int i = 0;
	while (i < 10)
	{
		vec.push_back(i * 4);
		i++;
	}
	/*--------------print vector---------------*/
	std::cout << BLUE << "vector = ";
	it = vec.begin();
	while(it != vec.end())
	{
		std::cout << (*it) << " ";
		it++;
	}
	std::cout << std::endl;
	/*----------------find-----------------*/
	std::cout << "Find 12 in int vector:" << std::endl;
	try
	{
		it = easyfind(vec, 12);
		std::cout << "--> " << *it << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "--> " << e.what() << '\n';
	}
}

void	dequeTest()
{
	std::deque<int> deq;
	std::deque<int>::iterator it;

	/*--------------fill deque---------------*/
	int i = 0;
	while (i < 10)
	{
		deq.push_back(i * 5);
		i++;
	}
	/*--------------print deque---------------*/
	std::cout << YELLOW << "deque = ";
	it = deq.begin();
	while(it != deq.end())
	{
		std::cout << (*it) << " ";
		it++;
	}
	std::cout << std::endl;
	/*----------------find-----------------*/
	std::cout << "Find 13 in int deque:" << std::endl;
	try
	{
		it = easyfind(deq, 13);
		std::cout << "--> " << *it << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "--> " << e.what() << '\n';
	}
}

void	listTest()
{
	std::list<int> li;
	std::list<int>::iterator it;

	/*--------------fill list---------------*/
	int i = 0;
	while (i < 10)
	{
		li.push_back(i); 
		i++;
	}
	/*--------------print list---------------*/
	std::cout << GREEN << "list = ";
	it = li.begin();
	while(it != li.end())
	{
		std::cout << (*it) << " ";
		it++;
	}
	std::cout << std::endl;
	/*----------------find-----------------*/
	std::cout << "Find 4 in int list:" << std::endl;
	try
	{
		it = easyfind(li, 4);
		std::cout << "--> " << *it << std::endl;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "--> " << e.what() << '\n';
	}	
}

int main()
{
	vectorTest();
	std::cout << "\n";
	dequeTest();
	std::cout << "\n";
	listTest();
}