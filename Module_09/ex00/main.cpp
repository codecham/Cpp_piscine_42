/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:09:47 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/20 18:50:22 by dcorenti         ###   ########.fr       */
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