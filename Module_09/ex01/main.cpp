/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:45:53 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/16 21:30:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN test;

	if (argc != 2)
	{
		std::cout << "Error bad arguments" << std::endl;
		return(0);
	}
	if (test.run(argv[1]) == false)
		std::cout << "Error" << std::endl;
}