/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:16 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/16 21:05:10 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <map>

class RPN
{
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN(void);
		RPN& operator=(const RPN& copy);
		bool run(char *str);

	private:
		std::map<int, int> _value;
		std::map<int, char> _op;

		bool checkValues(char value, char op);
		int  subOperation(char *str);
		bool addOperation(char value, char op);
		void doOperations();
		char getOp(const int index);
		int	 getValue(const int index);
		void printResult() const;
		int _index;
		int _result;
};

#endif