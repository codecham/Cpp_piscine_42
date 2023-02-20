/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:27:47 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/18 23:05:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy): AForm(copy._target, 25, 5), _target(copy._target)
{

}

PresidentialPardonForm::~PresidentialPardonForm(void)
{


}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

bool		PresidentialPardonForm::execute(Bureaucrat const & executor) const
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
	std::cout << GREEN << this->_target << RESET << " was forgiven by Zaphod Beeblebrox" << std::endl;
	return(true);
}

