/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:17:35 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/23 00:51:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Contact
{
	public:
		void ft_set_first_name();
		void ft_set_last_name();
		void ft_set_nickname();
		void ft_set_phone_number();
		void ft_set_darkest_secret();
		void ft_get_first_name();
		void ft_get_last_name();
		void ft_get_nickname();
		void ft_get_phone_number();
		void ft_get_darkest_secret();
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string phone_number;
		std::string darkest_secret;
};