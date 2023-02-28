/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 07:45:28 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 08:08:31 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base	*generate()
{
	srand(time(NULL));
	int		choice = rand() % 3;
	Base	*ptr = NULL;
	
	switch (choice)
	{
		case 0 :
			ptr = new A();
			break;
		case 1 :
			ptr = new B();
			break;
		case 2 :
			ptr = new C();
			break;
		default:
			break;
	}
	return(ptr);
}

void	identify(Base *p)
{
	A	*a = dynamic_cast<A*>(p);
	B	*b = dynamic_cast<B*>(p);
	C	*c = dynamic_cast<C*>(p);

	if (a)
		std::cout << "Class A" << std::endl;
	else if (b)
		std::cout << "Class B" << std::endl;
	else if (c)
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Unknow Class" << std::endl;
}

void	identify(Base &p)
{
	int i;

	i = 0;
	try
	{
		A a = dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	}
	catch(std::exception& e)
	{
		i++;
	}
	try
	{
		B b = dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;	
	}
	catch(std::exception& e)
	{
		i++;	
	}
	try
	{
		C c = dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
	}
	catch(std::exception& e)
	{
		i++;
	}
	if (i == 3)
		std::cout << "Unknow class" << std::endl;
}