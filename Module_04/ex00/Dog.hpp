/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 01:25:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		~Dog(void);
		Dog& operator=(const Dog& copy);

		void		makeSound() const;

};

#endif