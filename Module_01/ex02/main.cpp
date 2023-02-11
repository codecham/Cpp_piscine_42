/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:17:53 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/05 21:45:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "string adress:\t\t" << &str << std::endl;
	std::cout << "stringPTR adress:\t" << stringPTR << std::endl;
	std::cout << "stringREF adress:\t" << &stringREF << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "string value:\t\t" << str << std::endl;
	std::cout << "stringPTR value:\t" << *stringPTR << std::endl;
	std::cout << "stringREF value:\t" << stringREF << std::endl;
}