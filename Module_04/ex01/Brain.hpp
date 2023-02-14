/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 03:31:15 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/13 04:27:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& copy);
		virtual ~Brain(void);
		Brain& operator=(const Brain& copy);

		void		setIdea(std::string& idea, int index);
		std::string getIdea(int index) const;

	private:
		int _nb_ideas;
		std::string _ideas[100];
};

#endif