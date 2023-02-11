/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:05:21 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/04 19:30:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		void	add();
		void	search();
		void	fill_phone_book();
	private:
		Contact		contact_list[8];
		int			m_nb_contact;
		std::string	ask_first_name();
		std::string	ask_last_name();
		std::string	ask_nick_name();
		std::string	ask_phone();
		std::string	ask_secret();
		std::string str_set_size(std::string str) const;
		void		pop_front_contact();
		void		print_contact_list() const;
		void		print_contact(std::string index) const;

};

#endif