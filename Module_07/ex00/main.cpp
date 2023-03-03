/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:43:35 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 09:34:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Fixed.hpp"
#include <iostream>
#include <string.h>
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

int main()
{
	int a = 5;
	int b = 6;

	float cf = 2.4f;
	float df = 6.89f;

	char f = 'f';
	char g = 'g';

	std::string s1 = "Hello";
	std::string s2 = "World";

	Fixed x(45);
	Fixed y(89);

	std::cout << GREY << "-----------------INT TEST---------------" << BLUE << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min = " << ::min<int>(a, b) << std::endl;
	std::cout << "max = " << ::max<int>(a, b) << std::endl;
	std::cout << "swap a and b..." << std::endl;
	::swap<int>(a, b);
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << GREY << "\n-----------------FLOAT TEST---------------" << GREEN << std::endl;
	std::cout << "cf = " << cf << std::endl;
	std::cout << "df = " << df << std::endl;
	std::cout << "min = " << ::min<float>(cf, df) << std::endl;
	std::cout << "max = " << ::max<float>(cf, df) << std::endl;
	std::cout << "swap cf and df..." << std::endl;
	::swap<float>(cf, df);
	std::cout << "cf = " << cf << std::endl;
	std::cout << "df = " << df << std::endl;


	std::cout << GREY << "\n-----------------CHAR TEST---------------" << YELLOW << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "min = " << ::min<char>(f, g) << std::endl;
	std::cout << "max = " << ::max<char>(f, g) << std::endl;
	std::cout << "swap f and f..." << std::endl;
	::swap<char>(f, g);
	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;

	std::cout << GREY << "\n-----------------STRING TEST---------------" << CYAN << std::endl;
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;
	std::cout << "min = " << ::min<std::string>(s1, s2) << std::endl;
	std::cout << "max = " << ::max<std::string>(s1, s2) << std::endl;
	std::cout << "swap s1 and s2..." << std::endl;
	::swap<std::string>(s1, s2);
	std::cout << "s1 = " << s1 << std::endl;
	std::cout << "s2 = " << s2 << std::endl;

	std::cout << GREY << "\n-----------------CLASS TEST---------------" << MAGENTA << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "min = " << ::min<Fixed>(x, y) << std::endl;
	std::cout << "max = " << ::max<Fixed>(x, y) << std::endl;
	std::cout << "swap x and y..." << std::endl;
	::swap<Fixed>(x, y);
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
}