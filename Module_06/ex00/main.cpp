/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:42:31 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/24 21:15:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Scalar.hpp"

int main(int argc, char **argv)
{
	Scalar scl;

	if (argc == 2)
	{
		scl.convert(argv[1]);
		scl.printAll();
	}
	else
		std::cout << "Wrong number of argument! You can only run with 1 argument" << std::endl;
	
}