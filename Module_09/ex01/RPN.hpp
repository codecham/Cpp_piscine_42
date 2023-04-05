/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:40:16 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/06 00:32:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN(void);
		RPN& operator=(const RPN& copy);
		void	run(std::string str);

	private:
		std::stack<float> _stack;
		
		bool doOp(char op);
		bool isDigit(char c) const;
		bool isOp(char c) const;
		void erase_stack();
};

#endif