/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:24:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/10 22:23:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	PmergeMe test;

	if (argc < 2)
	{
		std::cout << "Need at least of 1 argument..." << std::endl;
		return(0);
	}
	if (!test.checkArg(argv))
		return (0);
	test.sort();
	// test.printList();
	// test.printTime();
}