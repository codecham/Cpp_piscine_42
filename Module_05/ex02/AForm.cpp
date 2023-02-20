/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:14:45 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/19 08:08:24 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 		"AForm.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

AForm::AForm(): _is_signed(false), _name("basic Aform") , _sign_grade(150), _exec_grade(150)
{
	std::cout << "A new default unsigned Aform named ";
	std::cout << GREEN << "basic Aform" << RESET;
	std::cout << " need to be signed by a grade ";
	std::cout << GREEN << "150" << RESET;
	std::cout << " and need to be executed by a grade ";
	std::cout << GREEN << "150" << RESET;
	std::cout << " was be created." << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade): _is_signed(false), _name(name) , _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	checkGrade(sign_grade, exec_grade);
	std::cout << "A new unsigned Aform named ";
	std::cout << GREEN << name << RESET;
	std::cout << " need to be signed by a grade ";
	std::cout << GREEN << sign_grade << RESET;
	std::cout << " and need to be executed by a grade ";
	std::cout << GREEN << exec_grade << RESET;
	std::cout << " was be created." << std::endl;
}

AForm::AForm(const AForm& copy): _is_signed(copy._is_signed), _name(copy._name) , _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade)
{
	std::cout << "A new Aform named ";
	std::cout << GREEN << copy._name << RESET;
	std::cout << " need to be signed by a grade ";
	std::cout << GREEN << copy._sign_grade << RESET;
	std::cout << " and need to be executed by a grade ";
	std::cout << GREEN << copy._exec_grade << RESET;
	std::cout << " was be created by copy. It's ";
	if (_is_signed == false)
		std::cout << GREEN << "unsigned" << RESET;
	else
		std::cout << GREEN << "signed" << RESET;
	std::cout << "." << std::endl;
}

AForm::~AForm(void)
{
	
}

AForm&	AForm::operator=(const AForm& copy)
{
	std::cout << "Operator = from AForm was be called" << std::endl;
	if (this != &copy)
		this->_is_signed = copy._is_signed;
	return(*this);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	std::cout << "A bureaucrat of grade ";
	std::cout << BLUE << bureaucrat.getGrade() << RESET;
	std::cout << " wants to sign a Aform that requires a grade ";
	std::cout << GREEN << this->_sign_grade << RESET;
	std::cout << "..." << std::endl;
	try
	{
		if (bureaucrat.getGrade() > this->_sign_grade)
			throw GradeTooLowException();
		else
			this->_is_signed = true;
	}
	catch(const std::exception& e)
	{
		std::cerr << GREY << e.what() << RESET << '\n';
	}
}

std::string	AForm::getName() const
{
	return(this->_name);
}

int			AForm::getSignGrade() const
{
	return(this->_sign_grade);
}

int			AForm::getExecGrade() const
{
	return(this->_exec_grade);
}

bool		AForm::getIsSigned() const
{
	return(this->_is_signed);
}

void		AForm::checkGrade(int gradeSign, int gradeExec) const
{
	try
	{
		if (gradeSign < 1 || gradeExec < 1)
			throw AForm::GradeTooHighException();
		else if (gradeSign > 150 || gradeExec > 150)
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << GREEN << this->_name << RESET << " cannot be create" << '\n';
		std::cerr << "Program interupted with this catch exeption: " << GREY << e.what() << RESET << '\n';
		exit(0);
	}
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "__Grade too High__";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "__Grade too Low__";
}

const char*	AForm::GradeTooLowForExec::what() const throw()
{
	return "__Grade too low for execute form__";
}

const char*	AForm::FormIsUnsigned::what() const throw()
{
	return "__Form is unsigned__";
}

std::ostream& operator<<(std::ostream& os, const AForm &Aform)
{
	os << "AForm ";
	os << GREEN << Aform.getName() << RESET;
	os << " need to be signed by a grade ";
	os << GREEN << Aform.getSignGrade() << RESET;
	os << ", need to be execute by a grade ";
	os << GREEN << Aform.getExecGrade() << RESET;
	os << " and it's ";
	if (Aform.getIsSigned() == false)
		os << GREEN << "unsigned" << RESET;
	else
		os << GREEN << "signed" << RESET;
	return(os);
}
