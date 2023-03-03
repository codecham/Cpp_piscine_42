/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 01:43:51 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/03 02:46:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <list>
#include <deque>
#include <map>
#include <algorithm>

class	NoOccurenceException : public std::exception
{
	public:
		virtual const char*	what() const throw (){
			return "No Occurence Found";
		}
};

template <typename T>
typename T::iterator	easyfind(T &container, int nb)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), nb);
	if (it == container.end())
		throw NoOccurenceException();
	return(it);
}

#endif