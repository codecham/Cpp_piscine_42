/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:06:33 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/08 21:31:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_hpp
#define Contact_hpp

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		Contact 	create_contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string secret);
		void		set_firstName(std::string firstName);
		void		set_lastName(std::string lastName);
		void		set_nickName(std::string nickName);
		void		set_phoneNumber(std::string phoneNumber);
		void		set_darkestSecret(std::string darkestSecret);
		std::string	get_firstName() const;
		std::string	get_lastName() const;
		std::string	get_nickName() const;
		std::string	get_phoneNumber() const;
		std::string	get_darkestSecret() const;

	private:
		std::string m_firstName;
		std::string m_lastName;
		std::string m_nickName;
		std::string m_phoneNumber;
		std::string m_darkestSecret;
};

#endif