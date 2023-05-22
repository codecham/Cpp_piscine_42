/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:46:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/05/22 22:13:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#define DATA_BASE_FILE "data.csv"
#define INPUT_FILE "input.txt"

int main(int argc, char **argv)
{
	BitcoinExchange binance;

	if (argc < 2)
		std::cout << "Error: could not open file" << std::endl;
	else if (argc > 2)
		std::cout << "You can only enter 1 argument" << std::endl;
	else
		binance.run(DATA_BASE_FILE, argv[1]);
}