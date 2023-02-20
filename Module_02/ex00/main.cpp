/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 00:24:30 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/17 09:58:33 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include<iostream>

int main(void) 
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	
	std::cout << "----------------------------" << std::endl;
	c = b;
	std::cout << "----------------------------" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	return(0);
}
