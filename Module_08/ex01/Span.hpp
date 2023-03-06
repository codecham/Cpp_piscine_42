/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:52:18 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/04 04:15:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span
{
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		~Span(void);
		Span& operator=(const Span& copy);
		
		void			add_number(int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addRange(int begin, int end);
		void			addRange(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		
		class	IsFull : public std::exception
		{
			public:
				virtual const char*	what() const throw ();
		};
		class	NoOccurenceFound : public std::exception
		{
			public:
				virtual const char*	what() const throw ();
		};
		class	WrongRange : public std::exception
		{
			public:
				virtual const char*	what() const throw ();
		};
		
	private:
		unsigned int		_size_max;
		std::vector<int> 	_vec;

};

#endif