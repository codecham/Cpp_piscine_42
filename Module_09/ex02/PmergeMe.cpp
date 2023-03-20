/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:13:23 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/20 19:47:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	_li = copy._li;
	_li_a = copy._li_a;
	_li_b = copy._li_b;
	_jacob = copy._jacob;
	_ve = copy._ve;
	_ve_a = copy._ve_a;
	_ve_b= copy._ve_b;
	_time_li = _time_li;
	_time_ve = _time_ve;
}

PmergeMe::~PmergeMe(void)
{

}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_li = copy._li;
		_li_a = copy._li_a;
		_li_b = copy._li_b;
		_jacob = copy._jacob;
		_ve = copy._ve;
		_ve_a = copy._ve_a;
		_ve_b= copy._ve_b;
		_time_li = _time_li;
		_time_ve = _time_ve;
	}
	return(*this);
}

/*------------------------------------------------------------------------------------------*/

bool	PmergeMe::checkAllDigit(char *str) const
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return(false);
		i++;
	}
	return (true);
}

bool	PmergeMe::checkIsInt(char *str)
{
	int i;
	long value;
	char *endptr;

	i = 0;
	while (str[i])
		i++;
	if (i > 10)
		return(false);
	value = strtol(str, &endptr, 10);
	if (value > INT_MAX)
		return (false);
	_li.push_back((int)value);
	_ve.push_back((int)value);
	return (true);
}

bool	PmergeMe::checkDouble()
{
	std::list<int> li_tmp(_li);
	std::list<int>::iterator it_li;
	std::list<int>::iterator it_li_tmp;

	li_tmp.sort();
	it_li = li_tmp.begin();
	it_li_tmp = li_tmp.begin();
	it_li_tmp++;
	while (it_li_tmp != li_tmp.end())
	{
		if (*it_li == *it_li_tmp)
			return(false);
		it_li++;
		it_li_tmp++;
	}
	return(true);
}

bool	PmergeMe::checkArg(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (!checkAllDigit(argv[i]))
			return (printError("Arguments must be only positives numbers"));
		if (!checkIsInt(argv[i]))
			return (printError("Arguments must be integers"));
		i++;
	}
	if (i == 2)
		return (printError("Need at least of 2 numbers for sorting"));
	if (!checkDouble())
		return (printError("Double numbers find"));
	build_jacobsthal();
	return(true);
}

void	PmergeMe::sort()
{
	unsigned long time;

	time = getTime();
	sortLi();
	_time_li = getTime() - time;
	time = getTime();
	sortVe();
	_time_ve = getTime() - time;
}

bool	PmergeMe::printError(std::string str) const
{
	std::cout << RED << "Error: "  << str << RESET << std::endl;
	return (false);
}

void	PmergeMe::printInitList()
{
	std::list<int>::iterator it;
	
	it = _li.begin();
	while (it != _li.end())
	{
		std::cout << *it << " ";
		it++;
	}
}

void	PmergeMe::printSortList()
{
	std::list<int>::iterator it;
	
	it = _li_a.begin();
	while (it != _li_a.end())
	{
		std::cout << *it << " ";
		it++;
	}
	// std::cout << "\nAfter vector: ";
	// std::vector<int>::iterator it_ve;
	
	// it_ve = _ve_a.begin();
	// while (it_ve != _ve_a.end())
	// {
	// 	std::cout << *it_ve << " ";
	// 	it_ve++;
	// }
}

void	PmergeMe::printList()
{
	std::cout << CYAN << "Before: ";
	printInitList();
	std::cout << std::endl;
	std::cout << GREEN << "After: ";
	printSortList();
	std::cout << RESET << std::endl;
}

void	PmergeMe::printTime()
{
	std::cout << "Time to process a range of " << _li.size() << " elements with std::list : " << YELLOW << _time_li << RESET << " us" << std::endl;
	std::cout << "Time to process a range of " << _li.size() << " elements with std::vector : " << YELLOW << _time_ve << RESET << " us" << std::endl;
}

unsigned long PmergeMe::getTime()
{
	timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_usec);
}

int 	PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void	 PmergeMe::build_jacobsthal()
{
	unsigned int index = 2;
	int			jacob_nb;
	int			last_jacob_nb = 0;
	int			value;
	int			size;

	size = _li.size() / 2;
	if (_li.size() % 2 == 1)
		size++;
	std::list<int>::iterator it;
	
	while (jacobsthal(index) < (int)_li.size() - 1)
	{
		jacob_nb = (jacobsthal(index));
		_jacob.push_back(jacob_nb);
		value = jacob_nb - 1;
		while (last_jacob_nb != 0 && value > last_jacob_nb)
		{
			_jacob.push_back(value);
			value--;
		}
		index++;
		last_jacob_nb = jacob_nb;
	}
	it = _jacob.begin();
	while (it != _jacob.end())
	{
		if (*it >= size)
			it = _jacob.erase(it);
		else
			it++;
	}
}

/*--------------------------------------LIST FUNCTIONS-----------------------------------------*/

void	PmergeMe::sortLi()
{
	std::list<int>::iterator it;
	std::list<int>::iterator next_it;
	
	it = _li.begin();
	next_it = ++_li.begin();
	sortPairsLi(it, next_it);
	sortLiA();
	mergeLi();
}

void	PmergeMe::mergeLi()
{
	std::list<int>::iterator it_b;
	std::list<int>::iterator it_jacob;
	unsigned int i;
	int value;

	i = 0;
	it_b = _li_b.begin();
	it_jacob = _jacob.begin();
	_li_a.push_front(*it_b);
	while (i < _jacob.size())
	{
		std::advance(it_b, *it_jacob);
		value = *it_b;
		binarysearchLi(value);
		i++;
		it_jacob++;
		it_b = _li_b.begin();
	}
}

int		PmergeMe::binarycheckLi(std::list<int>::iterator& it, int value)
{
	std::list<int>::iterator previous;

	previous = it;
	previous--;
	if ((value > *previous && value < *it) || (value > *it && it == _li_a.end()))
	{
		it = _li_a.insert(it, value);
		return(0);
	}
	if (value < *it)
		return (-1);
	return (1);
}

void	PmergeMe::binarysearchLi(int value)
{
	std::list<int>::iterator it;
	int ret;
	int index;
	
	it = _li_a.begin();
	if (value < *it)
	{
		_li_a.push_front(value);
		return ;
	}
	index = _li_a.size() / 2;
	std::advance(it, index);
	while (1)
	{
		index /= 2;
		if (index == 0)
			index++;
		ret = binarycheckLi(it, value);
		if (ret == 0)
			break ;
		else if (ret == -1)
			std::advance(it, (index * -1));
		else
			std::advance(it, index);
	}
}

void	PmergeMe::sortPairsLi(std::list<int>::iterator& it, std::list<int>::iterator& next_it)
{
	int tmp;

	if (it == _li.end() || next_it == _li.end())
		return ;
	if (*it > *next_it)
	{
		tmp = *it;
		*it = *next_it;
		*next_it = tmp;
	}
	_li_b.push_back(*it);
	_li_a.push_back(*next_it);
	it++;
	it++;
	next_it++;
	next_it++;
	if (next_it == _li.end())
		_li_b.push_back(*it);
	sortPairsLi(it, next_it);
}

void	PmergeMe::sortLiA()
{
	std::list<int>::iterator it_a;
	std::list<int>::iterator it_next_a;
	std::list<int>::iterator it_b;
	std::list<int>::iterator it_next_b;
	int tmp;
	unsigned int i;
	
	it_a = _li_a.begin();
	it_b = _li_b.begin();
	it_next_a = _li_a.begin();
	it_next_b = _li_b.begin();
	it_next_a++;
	it_next_b++;
	i = 0;
	while (i < _li_a.size())
	{
		while (it_next_a != _li_a.end())
		{
			if (*it_a > *it_next_a)
			{
				tmp = *it_a;
				*it_a = *it_next_a;
				*it_next_a = tmp;
				tmp = *it_b;
				*it_b = *it_next_b;
				*it_next_b = tmp;
			}
			it_a++;
			it_b++;
			it_next_a++;
			it_next_b++;
		}
		it_a = _li_a.begin();
		it_b = _li_b.begin();
		it_next_a = _li_a.begin();
		it_next_b = _li_b.begin();
		it_next_a++;
		it_next_b++;
		i++;
	}
}

/*--------------------------------------VECTOR FUNCTIONS-----------------------------------------*/

void	PmergeMe::sortVe()
{
	std::vector<int>::iterator it;
	std::vector<int>::iterator next_it;
	
	it = _ve.begin();
	next_it = ++_ve.begin();
	sortPairsVe(it, next_it);
	sortVeA();
	mergeVe();
}

void 	PmergeMe::mergeVe()
{
	std::vector<int>::iterator it_a;
	std::vector<int>::iterator it_b;
	std::list<int>::iterator it_jacob;
	unsigned int i;
	int value;

	i = 0;
	it_a = _ve_a.begin();
	it_b = _ve_b.begin();
	it_jacob = _jacob.begin();
	it_a = _ve_a.insert(it_a, *it_b);
	it_a = _ve_a.begin();
	while (i < _jacob.size())
	{
		std::advance(it_b, *it_jacob);
		value = *it_b;
		binarysearchVe(value);
		i++;
		it_jacob++;
		it_b = _ve_b.begin();
	}
}

int  	PmergeMe::binarycheckVe(std::vector<int>::iterator& it, int value)
{
	std::vector<int>::iterator previous;

	previous = it;
	previous--;
	if ((value > *previous && value < *it) || (value > *it && it == _ve_a.end()))
	{
		it = _ve_a.insert(it, value);
		return(0);
	}
	if (value < *it)
		return (-1);
	return (1);
	
}

void 	PmergeMe::binarysearchVe(int value)
{
	std::vector<int>::iterator it;
	int ret;
	int index;
	
	it = _ve_a.begin();
	if (value < *it)
	{
		it = _ve_a.insert(it, value);
		return ;
	}
	index = _ve_a.size() / 2;
	std::advance(it, index);
	while (1)
	{
		index /= 2;
		if (index == 0)
			index++;
		ret = binarycheckVe(it, value);
		if (ret == 0)
			break ;
		else if (ret == -1)
			std::advance(it, (index * -1));
		else
			std::advance(it, index);
	}
}

void	PmergeMe::sortPairsVe(std::vector<int>::iterator& it, std::vector<int>::iterator& next_it)
{
	int tmp;

	if (it == _ve.end() || next_it == _ve.end())
		return ;
	if (*it > *next_it)
	{
		tmp = *it;
		*it = *next_it;
		*next_it = tmp;
	}
	_ve_b.push_back(*it);
	_ve_a.push_back(*next_it);
	it++;
	it++;
	next_it++;
	next_it++;
	if (next_it == _ve.end())
		_ve_b.push_back(*it);
	sortPairsVe(it, next_it);
}

void	PmergeMe::sortVeA()
{
	std::vector<int>::iterator it_a;
	std::vector<int>::iterator it_next_a;
	std::vector<int>::iterator it_b;
	std::vector<int>::iterator it_next_b;
	int tmp;
	unsigned int i;
	
	it_a = _ve_a.begin();
	it_b = _ve_b.begin();
	it_next_a = _ve_a.begin();
	it_next_b = _ve_b.begin();
	it_next_a++;
	it_next_b++;
	i = 0;
	while (i < _ve_a.size())
	{
		while (it_next_a != _ve_a.end())
		{
			if (*it_a > *it_next_a)
			{
				tmp = *it_a;
				*it_a = *it_next_a;
				*it_next_a = tmp;
				tmp = *it_b;
				*it_b = *it_next_b;
				*it_next_b = tmp;
			}
			it_a++;
			it_b++;
			it_next_a++;
			it_next_b++;
		}
		it_a = _ve_a.begin();
		it_b = _ve_b.begin();
		it_next_a = _ve_a.begin();
		it_next_b = _ve_b.begin();
		it_next_a++;
		it_next_b++;
		i++;
	}
}