/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:54:29 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:53:47 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& copy);
		virtual ~Animal(void);
		Animal& operator=(const Animal& copy);

		void				setType(std::string type);
		std::string			getType() const;
		virtual void		makeSound() const = 0;
		
	protected:
		std::string _type;
};

#endif