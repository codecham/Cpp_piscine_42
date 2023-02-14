/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:17 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:26:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(const Dog& copy);
		virtual ~Dog(void);
		Dog& operator=(const Dog& copy);

		virtual void	makeSound() const;
		std::string 	getIdea(int index) const;
		void 	 		setIdea(std::string idea, int index);

	private:
		Brain* brain;

};

#endif