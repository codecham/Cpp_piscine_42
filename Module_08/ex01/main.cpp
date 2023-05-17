/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:41:48 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/29 21:47:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
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
	Span sp(10000);
	Span sp_2(1000);
	std::vector<int> vector;
	int i;

	i = 0;
	std::cout << GREY << "Try with a vector of size of 10000" << RESET << std::endl;
	sp.addRange(1, 10000);
	std::cout << "Shortest Span = " << BLUE << sp.shortestSpan() << RESET << std::endl;
	std::cout << "Longest Span = " << BLUE << sp.longestSpan() << RESET << std::endl;
	std::cout << std::endl;

	std::cout << GREY << "Try with add an range of vector with iterators" << RESET << std::endl;
	while(i < 10)
	{
		vector.push_back(i);
		i++;
	}
	sp_2.addRange(vector.begin(), vector.end());
	std::cout << "Shortest Span = " << BLUE << sp_2.shortestSpan() << RESET << std::endl;
	std::cout << "Longest Span = " << BLUE << sp_2.longestSpan() << RESET << std::endl;
	std::cout << std::endl;
}
