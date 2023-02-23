/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/23 01:24:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(const Cat& copy);
		~Cat(void);
		Cat& operator=(const Cat& copy);

		void		makeSound() const;

};

#endif