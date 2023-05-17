/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:09:40 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/29 21:46:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#define RESET   "\033[0m"
#define GREY    "\033[38;5;8m"

Span::Span()
{
	this->_size_max = 0;
}

Span::Span(unsigned int n)
{
	this->_size_max = n;
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::~Span()
{
	
}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		this->_size_max = copy._size_max;
		this->_vec = copy._vec;
	}
	return(*this);
}

void	Span::add_number(int nb)
{
	try
	{
		if (this->_vec.size() >= this->_size_max)
			throw IsFull();
		this->_vec.push_back(nb);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}
}

// unsigned int Span::shortestSpan()
// {
// 	std::vector<int>::iterator it;
// 	int diff_min;
// 	int diff_tmp;

// 	try
// 	{
// 		if (this->_vec.size() < 2)
// 			throw NoOccurenceFound();
// 		std::sort(this->_vec.begin(), this->_vec.end());
// 		it = this->_vec.end() - 1;
// 		diff_min = *it - *--it;
// 		while(it != _vec.begin())
// 		{
// 			diff_tmp = *it - *--it;
// 			if (diff_tmp < diff_min)
// 				diff_min = diff_tmp;
// 		}
// 		return(diff_min);
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << GREY << e.what() << RESET << '\n';
// 		return(0);
// 	}
// }

unsigned int Span::shortestSpan()
{
	std::vector<int> copy_vec = _vec;
	std::vector<int>::iterator it;
	std::vector<int>::iterator it_next;
	int diff_min;

	try
	{
		if (copy_vec.size() < 2)
			throw NoOccurenceFound();
		std::sort(copy_vec.begin(), copy_vec.end());
		it = copy_vec.begin();
		it_next = it + 1;
		diff_min = *it_next - *it;
		while (it_next != copy_vec.end())
		{
			if ((*it_next - *it) < diff_min)
				diff_min = *it_next - *it;
			it++;
			it_next++;
		}
		return(diff_min);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
		return(0);
	}
}

unsigned int Span::longestSpan()
{
	std::vector<int> copy_vec = _vec;
	
	try
	{
		if (copy_vec.size() < 2)
			throw NoOccurenceFound();
		std::sort(copy_vec.begin(), copy_vec.end());
		return(copy_vec.at(copy_vec.size() - 1) - copy_vec.at(0));
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
		return(0);
	}
}

void	Span::addRange(int begin, int end)
{
	try
	{
		if (begin >= end || (unsigned int)(end - begin) > this->_size_max)
			throw WrongRange();
		while (begin <= end)
		{
			add_number(begin);
			begin++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}
}

void	Span::addRange(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	int distance = std::distance(begin, end);
	try
	{
		if (distance + this->_vec.size() > this->_size_max)
			throw WrongRange();
		this->_vec.insert(this->_vec.end(), begin, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << '\n';
	}
}

const char*	Span::IsFull::what() const throw ()
{
	return("__Span_Exception::isFull__");
}

const char*	Span::NoOccurenceFound::what() const throw ()
{
	return("__Span_Exception::NoOccurenceFound__");
}

const char*	Span::WrongRange::what() const throw ()
{
	return("__Span_Exception::WrongRange__");
}

