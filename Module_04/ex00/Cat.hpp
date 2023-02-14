/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 23:26:20 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/14 22:02:30 by dcorenti         ###   ########.fr       */
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
		virtual ~Cat(void);
		Cat& operator=(const Cat& copy);

		virtual void		makeSound() const;

};

#endif