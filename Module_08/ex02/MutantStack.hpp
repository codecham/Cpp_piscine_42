/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 05:34:05 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/05 05:34:47 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename Container=std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:

	public:
		MutantStack(void) {};
		~MutantStack(void) {};
		MutantStack(MutantStack const *copy) : std::stack<T, Container>(copy){}
		MutantStack &operator=(MutantStack const &copy) 
		{
			std::stack<T, Container>::operator=(copy);
			return *this;
		}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
		reverse_iterator rbegin() {return this->c.rbegin();}
		reverse_iterator rend() {return this->c.rend();}
};

#endif