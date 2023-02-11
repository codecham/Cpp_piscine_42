/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:58:38 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 21:21:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "\033[1;31mERROR\nNEED ONE PARAMETER" << std::endl;
		return (0);
	}
	harl.complain(argv[1]);
}