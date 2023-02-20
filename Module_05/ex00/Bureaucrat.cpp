/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:15:06 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 20:41:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define GREY    "\033[38;5;8m"

Bureaucrat::Bureaucrat() : _name("John"), _grade(150)
{
	std::cout << "A new default bureacrate named ";
	std::cout << BLUE << "John" << RESET;
	std::cout << " with grade " ;
	std::cout << BLUE << "150" << RESET;
	std::cout << " was be created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name), _grade(grade)
{
	checkGrade(grade);
	std::cout << "A new bureacrate named ";
	std::cout << BLUE << name << RESET;
	std::cout << " with grade " ;
	std::cout << BLUE << grade << RESET;
	std::cout << " was be created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	std::cout << "A new bureacrate by copy named ";
	std::cout << BLUE << _name << RESET;
	std::cout << " with grade " ;
	std::cout << BLUE << _grade << RESET;
	std::cout << " was be created" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor from Bureaucrat was be called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& copy)
{
	std::cout << "Operator = from Bureaucrat was be called" << std::endl;
	if (this != &copy)
		_grade = copy._grade;
	return(*this);
}


void		Bureaucrat::setGrade(int grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
		this->_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cerr << BLUE << this->_name << RESET << " cannot be incremented" << '\n';
	}
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void		Bureaucrat::increment()
{
	try
	{
		if (this->_grade <= 1)
			throw GradeTooHighException();
		this->_grade--;
	}
	catch(const std::exception& e)
	{
		std::cerr << BLUE << this->_name << RESET << " cannot be incremented" << '\n';
	}
}

void		Bureaucrat::decrement()
{
	try
	{
		if (this->_grade >= 150)
			throw GradeTooLowException();
		this->_grade++;
	}
	catch(const std::exception& e)
	{
		std::cerr << BLUE << this->_name << RESET << " cannot be decremented" << '\n';
	}
}

void	Bureaucrat::checkGrade(int grade) const
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << BLUE << this->_name << RESET << " cannot be create" << '\n';
		std::cerr << "Program interupted with this catch exeption: " << GREY << e.what() << RESET << '\n';
		exit(0);
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << BLUE << bureaucrat.getName() << RESET;
	os << " bureaucrat's grade is ";
	os << BLUE << bureaucrat.getGrade() << RESET;
	os << ".";
	return(os);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too Low";
}

