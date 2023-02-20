/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:05:11 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/19 08:01:12 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	public:
		Form();
		Form(std::string name, int sign_grade, int exec_grade);
		Form(const Form& copy);
		~Form(void);
		Form& operator=(const Form& copy);
		
		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;
		void		beSigned(const Bureaucrat& bureaucrat);

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

	private:
		bool				_is_signed;
		std::string const 	_name;
		int	const 			_sign_grade;
		int const 			_exec_grade;
		void		checkGrade(int gradeSign, int gradeExec) const;
		
};

std::ostream& operator<<(std::ostream& os, const Form &form);

#endif