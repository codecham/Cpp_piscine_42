/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:05:11 by dcorenti          #+#    #+#             */
/*   Updated: 2023/04/29 01:07:55 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	public:
		AForm();
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(const AForm& copy);
		virtual ~AForm(void);
		AForm& operator=(const AForm& copy);
		
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat& bureaucrat);
		virtual bool		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class GradeTooLowForExec : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class FormIsUnsigned : public std::exception
		{
			public:
				const char*	what() const throw();
		};

	private:
		bool				_is_signed;
		std::string const 	_name;
		int	const 			_sign_grade;
		int const 			_exec_grade;

	protected:
		void				checkGrade(int gradeSign, int gradeExec) const;
		
};

std::ostream& operator<<(std::ostream& os, const AForm &form);

#endif