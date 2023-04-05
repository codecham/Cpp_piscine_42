/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:45:53 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/06 00:07:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv)
{
	RPN test;

	if (argc != 2)
	{
		std::cout << "Error bad arguments" << std::endl;
		return(0);
	}
	test.run(argv[1]);
}