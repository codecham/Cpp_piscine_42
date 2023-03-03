/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:40:26 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/28 09:33:27 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T const	&min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template<typename T>
T const	&max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif