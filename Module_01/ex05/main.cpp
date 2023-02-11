/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 20:58:38 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 21:17:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harl;

	std::cout << "Sending DEBUG to Harl:" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\nSending INFO to Harl:" << std::endl;
	harl.complain("INFO");
	std::cout << "\nSending WARNING to Harl:" << std::endl;
	harl.complain("WARNING");
	std::cout << "\nSending ERROR to Harl:" << std::endl;
	harl.complain("ERROR");
}