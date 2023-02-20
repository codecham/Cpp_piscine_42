/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:37:14 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/18 23:08:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm(target, 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy._target, 145, 137), _target(copy._target)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		this->_target = copy._target;
	}
	return (*this);
}

bool		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string file_name = _target + "_shrubbery";
	std::ofstream file;

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
	file.open(file_name);
	try
	{
		if (!file)
			throw ShrubberyError();
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
		return(false);	
	}
	file << "         X         " << std::endl;
	file << "         *         " << std::endl;
	file << "        ***        " << std::endl;
	file << "       *****       " << std::endl;
	file << "      *******      " << std::endl;
	file << "     *********     " << std::endl;
	file << "    ***********    " << std::endl;
	file << "   *************   " << std::endl;
	file << "  ***************  " << std::endl;
	file << "        |||        " << std::endl;
	file << "        |||        " << std::endl;
	file << "..................." << std::endl;
	return (true);
}

const char*	ShrubberyCreationForm::ShrubberyError::what() const throw()
{
	return "Couldn't Create file _shrubbery";
}