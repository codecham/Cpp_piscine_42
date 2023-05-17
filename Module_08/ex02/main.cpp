/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:02:01 by dcorenti          #+#    #+#             */
/*   Updated: 2023/05/17 17:53:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main()
{
	MutantStack<int>    mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while(it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack); // test the copy constructor

	/*
		Same tests with vectors. If the result is the same that's means that our MutanStack works
	*/

	std::cout << "\nSame test with vector:" << std::endl;
	std::vector<int>    vector;
	vector.push_back(5);
	vector.push_back(17);
	std::cout << vector.back() << std::endl;
	vector.pop_back();
	std::cout << vector.size() << std::endl;
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(737);

	vector.push_back(0);
	std::vector<int>::iterator it_v = vector.begin();
	std::vector<int>::iterator ite_v = vector.end();
	++it_v;
	--it_v;
	while(it_v != ite_v)
	{
		std::cout << *it_v << std::endl;
		++it_v;
	}
	return 0;
}

// You can try with other containers, just don't forget to replace the functions by there version for the containers that you use for test (For exemple: push of stack become push_back for vector. 