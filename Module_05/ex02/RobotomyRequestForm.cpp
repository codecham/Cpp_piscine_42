/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 21:28:22 by dcorenti          #+#    #+#             */
/*   Updated: 2023/03/15 22:57:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy): AForm(copy._target, 72, 45), _target(copy._target)
{

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

bool		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (!this->getIsSigned())
			throw FormIsUnsigned();
		else if (executor.getGrade() > this->getExecGrade())
			throw GradeTooLowForExec();
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
		return(false);
	}
	std::cout << GREY << "*Loud and unpleasant drill noises*" << RESET << std::endl;
	std::srand(std::time(nullptr));
	int random_int = std::rand() % 2;
	if (random_int == 0)
	{
		std::cout << GREEN << this->_target << RESET << " has been " << RED << "not robotomized!" <<  RESET << std::endl;
	}
	else
		std::cout << GREEN << this->_target << RESET << " has been " << GREEN << "robotomized!" << RESET << std::endl;	
	return(true);
}

const char* RobotomyRequestForm::ErrorRobotomy::what() const throw()
{
	return "Robotomy failed";
}
