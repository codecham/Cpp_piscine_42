/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:52:42 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 08:25:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Aform;
class Intern
{
	public:
		Intern();
		Intern(const Intern& copy);
		~Intern(void);
		Intern& operator=(const Intern& copy);
		AForm *makeForm(std::string form_name, std::string target);
	
	private:
		AForm *createShrubbery(std::string target);
		AForm *createPardon(std::string target);
		AForm *createRobotomy(std::string target);
};

#endif