/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:07:54 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/18 22:41:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <cctype>
#include <limits>
#include <iterator>
#include <ctime>
#include <sys/time.h>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe(void);
		PmergeMe& operator=(const PmergeMe& copy);

		bool	checkArg(char **argv);
		void	printList();
		void	printTime();
		void	sort();

	private:
		std::list<int>	_li;
		std::list<int>	_li_a;
		std::list<int>	_li_b;
		std::list<int>  _jacob;
		std::vector<int> _ve;
		std::vector<int> _ve_a;
		std::vector<int> _ve_b;

		unsigned long _time_li;
		unsigned long _time_ve;
		

		bool 			checkAllDigit(char *str) const ;
		bool 			checkIsInt(char *str);
		bool 			printError(std::string str) const;
		unsigned long 	getTime();
		int 			jacobsthal(int n);
		void			build_jacobsthal();
		void			printInitList();
		void			printSortList();
		
		void sortLi();
		void sortPairsLi(std::list<int>::iterator& it, std::list<int>::iterator& next_it);
		void sortLiA();
		void mergeLi();
		void binarysearchLi(int value);
		int  binarycheckLi(std::list<int>::iterator& it, int value);

		void sortVe();
		void sortPairsVe(std::vector<int>::iterator& it, std::vector<int>::iterator& next_it);
		void sortVeA();
		void mergeVe();
		void binarysearchVe(int value);
		int  binarycheckVe(std::vector<int>::iterator& it, int value);
};

#endif