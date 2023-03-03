/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:39:03 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 10:24:17 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *arrayAdress, unsigned int lenght, void (funtion)(T &arrayMember))
{
	unsigned int i;

	i  = 0;
	while (i < lenght)
	{
		funtion(arrayAdress[i]);
		i++;
	}
}

template<typename T>
void	iter(T const *arrayAdress, unsigned int lenght, void (funtion)(T const &arrayMember))
{
	unsigned int i;

	i  = 0;
	while (i < lenght)
	{
		funtion(arrayAdress[i]);
		i++;
	}
}

template<typename T>
void	addOne(T &n)
{
	n += 1.0;
}

template<typename T>
void	doubleValue(T &n)
{
	n *= 2;
}

template<typename T>
void	print(T const &n)
{
	std::cout << n << std::endl;
}

template<typename T>
void	mutliplyClass(T &n)
{
	T const tmp(n);

	n = n * tmp;
}



#endif