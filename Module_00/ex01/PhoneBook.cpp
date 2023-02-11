/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:06:02 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/04 19:48:33 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook()
{
	m_nb_contact = 0;	
}

void	PhoneBook::fill_phone_book()
{
	contact_list[0] = contact_list[0].create_contact("Benjamin", "Hols", "Durif", "0000000", "Petit con");
	contact_list[1] = contact_list[1].create_contact("Balou", "Balt", "Eliot", "111111", "Aime la biere");
	contact_list[2] = contact_list[2].create_contact("Elliott", "Motte", "2l2t", "2222222", "Gros fumeur de weed");
	contact_list[3] = contact_list[3].create_contact("Aurelie", "Jamar", "Auré", "3333333", "Architecte en herbe");
	contact_list[4] = contact_list[4].create_contact("Lola", "VH", "Lolo", "44444444", "Boulangere endurcie");
	contact_list[5] = contact_list[5].create_contact("Robin", "Danhier", "RobinShape", "55555555", "Pire qu'un Abra");
	contact_list[6] = contact_list[6].create_contact("Corentin", "Dechamps", "Coco", "6666666", "Trop bon en code");
	contact_list[7] = contact_list[7].create_contact("Clement", "Tournis", "Clem", "7777777", "Bobo ecolo");
	m_nb_contact = 8;
}

std::string PhoneBook::ask_first_name()
{
	std::string input;

	getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Enter the first name:" << std::endl;
		getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty...!\n" << std::endl;
	}
	return (input);
}

std::string PhoneBook::ask_last_name()
{
	std::string input;

	while (input.empty())
	{
		std::cout << "Enter the last name:" << std::endl;
		getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!\n" << std::endl;
	}
	return (input);
}

std::string PhoneBook::ask_nick_name()
{
	std::string input;
	
	while (input.empty())
	{
		std::cout << "Enter the nickname:" << std::endl;
		getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!\n" << std::endl;
	}
	return (input);
}

std::string PhoneBook::ask_phone()
{
	std::string input;
	bool		check;
	int			count;
	
	check = false;
	count = 0;
	while (!check)
	{
		std::cout << "Enter the phone number:" << std::endl;
		getline(std::cin, input);
		count = strspn(input.c_str(), "0123456789");
		if (input.empty())
			std::cout << "This field can't be empty!\n" << std::endl;
		else if (count != (int)input.size())
			std::cout << "This field can contains only digit" << std::endl;
		else
			check = true;
	}
	return (input);
}

std::string PhoneBook::ask_secret()
{
	std::string input;
	
	while (input.empty())
	{
		std::cout << "Enter the darkest secret:" << std::endl;
		getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!\n" << std::endl;
	}
	return (input);
}

std::string PhoneBook::str_set_size(std::string str) const
{
	std::string new_str;
	int i;

	i = 0;
	if (str.size() > 10)
	{
		new_str = str;
		new_str.resize(9);
		new_str += ".";
	}
	else
	{
		while (i < (int)(10 - str.size()))
		{
			new_str[i] = ' '; 
			i++;
		}
		new_str += str;
	}
	return (new_str);
}

void	PhoneBook::print_contact_list() const
{
	int i;

	i = 0;
	while (i < m_nb_contact)
	{
		std::cout << "|";
		std::cout << std::setw(10) << str_set_size(std::to_string(i + 1)) << "|";
		std::cout << std::setw(10) << str_set_size(contact_list[i].get_firstName()) << "|";
		std::cout << std::setw(10) << str_set_size(contact_list[i].get_lastName()) << "|";
		std::cout << std::setw(10) << str_set_size(contact_list[i].get_nickName()) << "|" << std::endl;
		i++;
	}
	std::cout << "---------------------------------" << std::endl;
}

void	PhoneBook::print_contact(std::string choice) const
{
	int index;

	index = stoi(choice) - 1;
	if (index >= m_nb_contact)
	{
		std::cout << "[" << choice << "]: Incorrect format. Only one number between 1 and " << m_nb_contact << std::endl;
		return ;
	}
	std::cout << "First name: " << contact_list[index].get_firstName() << std::endl;
	std::cout << "Last name: " << contact_list[index].get_lastName() << std::endl;
	std::cout << "Nickname: " << contact_list[index].get_nickName() << std::endl;
	std::cout << "Phone number: " << contact_list[index].get_phoneNumber() << std::endl;
	std::cout << "Darkest secret: " << contact_list[index].get_darkestSecret() << std::endl;
}

void	PhoneBook::pop_front_contact()
{
	int i;

	i = 0;
	while (i < 7)
	{
		contact_list[i].set_firstName(contact_list[i + 1].get_firstName());
		contact_list[i].set_lastName(contact_list[i + 1].get_lastName());
		contact_list[i].set_nickName(contact_list[i + 1].get_nickName());
		contact_list[i].set_phoneNumber(contact_list[i + 1].get_phoneNumber());
		contact_list[i].set_darkestSecret(contact_list[i + 1].get_darkestSecret());
		i++;
	}
}

void	PhoneBook::add()
{
	int i;

	i = 0;
	std::cout << "---------------------------------" << std::endl;
	while (i < m_nb_contact)
		i++;
	if (i > 7)
	{
		pop_front_contact();
		i = 7;
	}
	contact_list[i].set_firstName(ask_first_name());
	contact_list[i].set_lastName(ask_last_name());
	contact_list[i].set_nickName(ask_nick_name());
	contact_list[i].set_phoneNumber(ask_phone());
	contact_list[i].set_darkestSecret(ask_secret());
	if (m_nb_contact < 8)
		m_nb_contact++;
}

void	PhoneBook::search()
{
	std::string choice;

	std::cout << "---------------------------------" << std::endl;
	if (m_nb_contact <= 0)
	{
		std::cout << "Your Phone Book is empty..." << std::endl;
		return ;
	}
	print_contact_list();
	std::cout << "Which contact do you want to display?" << std::endl;
	std::cin >> choice;
	if (choice.size() != 1 || (choice[0] < '1' || choice[0] > '8'))
	{
		std::cout << "[" << choice << "]: Incorrect format. Only one number between 1 and " << m_nb_contact << std::endl;
		return ;
	}
	print_contact(choice);
}