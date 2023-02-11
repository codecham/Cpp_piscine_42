/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:08:01 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/04 19:34:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact Contact::create_contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber, std::string secret)
{
	Contact new_contact;
	
	new_contact.m_firstName = firstName;
	new_contact.m_lastName = lastName;
	new_contact.m_nickName = nickName;
	new_contact.m_phoneNumber = phoneNumber;
	new_contact.m_darkestSecret = secret;
	return (new_contact);
}

void Contact::set_firstName(std::string firstName)
{
	m_firstName = firstName;
}

void Contact::set_lastName(std::string lastName)
{
	m_lastName = lastName;
}

void Contact::set_nickName(std::string nickName)
{
	m_nickName = nickName;
}

void Contact::set_phoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void Contact::set_darkestSecret(std::string darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

std::string Contact::get_firstName() const
{
	return(m_firstName);
}

std::string Contact::get_lastName() const
{
	return(m_lastName);
}
std::string Contact::get_nickName() const
{ 
	return(m_nickName);
}

std::string Contact::get_phoneNumber() const
{
	return(m_phoneNumber);
}

std::string Contact::get_darkestSecret() const
{
	return(m_darkestSecret);
}