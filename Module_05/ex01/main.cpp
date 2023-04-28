/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:30:23 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/28 23:00:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat allan("Allan", 20);
	Form form_one("A30-A", 10, 10);
	Form form_tow("B30-B", 20, 20);
	Form form_three("C30-C", 30, 30);

	std::cout << "------------------------------------------------\n\n" << std::endl;
	
	allan.sign_form(form_one);
	std::cout << "------------------------------------------------\n\n" << std::endl;

	allan.sign_form(form_tow);
	std::cout << "------------------------------------------------\n\n" << std::endl;

	allan.sign_form(form_three);
	std::cout << "------------------------------------------------\n\n" << std::endl;

	std::cout << form_one << std::endl;
	std::cout << form_tow << std::endl;
	std::cout << form_three << std::endl;
	std::cout << "------------------------------------------------\n\n" << std::endl;
}
