/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:26:59 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		virtual ~Cat(void);
		Cat& operator=(const Cat& copy);

		virtual void	makeSound() const;
		std::string 	getIdea(int index) const;
		void 	 		setIdea(std::string idea, int index);

	private:
		Brain* brain;
};

#endif