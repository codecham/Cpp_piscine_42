/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 02:02:14 by dcorenti         ###   ########.fr       */
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
		~Cat(void);
		Cat& operator=(const Cat& copy);

		void			makeSound() const;
		std::string 	getIdea(int index) const;
		void 	 		setIdea(std::string idea);

	private:
		Brain* _brain;
};

#endif