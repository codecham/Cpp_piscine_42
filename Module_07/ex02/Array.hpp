/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:11:34 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/02 19:16:58 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <exception>
#include <iostream>

template<typename T>
class Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array(void);
		Array& operator=(const Array& copy);

		unsigned int size() const;
		T&	operator[](unsigned int index);

	private:
		T*	_tab;
		unsigned int _size;
};

template<typename T>
Array<T>::Array()
{
	this->_tab = NULL;
	this->_size = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n > 0)
		this->_tab = new T[n];
	else
		this->_tab = NULL;
	this->_size = n;
	while (i < n)
	{
		this->_tab[i] = 0;
		i++;
	}
}
template<typename T>
Array<T>::Array(const Array& copy)
{
	unsigned int i;

	i = 0;
	if (copy._tab == NULL)
	{
		this->_tab = NULL;
		this->_size = 0;
	}
	else
	{
		this->_size = copy._size;
		this->_tab = new T[copy._size];
		while (i < copy._size)
		{
			this->_tab[i] = copy._tab[i];
			i++;
		}
	}
}

template <typename T>
Array<T>::~Array()
{
	if (this->_tab)
		delete [] _tab;
	return;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	unsigned int i;

	i = 0;
	if (this != &copy)
	{
		if (this->_tab)
			delete [] _tab;
		if (copy._tab == NULL)
		{
			this->_tab = NULL;
			this->_size = 0;
		}
		else
		{
			this->_size = copy._size;
			this->_tab = new T[copy._size];
			while (i < copy.size())
			{
				this->_tab[i] = copy._tab[i];
				i++;
			}
		}
	}
	return(*this);
}

class InvalidIndexException : public std::exception {
	public:
		virtual const char* what()const throw() {
			return ("Invalid index");
		}
};

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index >= this->_size)
		throw InvalidIndexException();
	return(this->_tab[index]);
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return(this->_size);
}

#endif