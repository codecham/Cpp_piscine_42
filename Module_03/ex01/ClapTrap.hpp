/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:04:43 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/12 21:38:11 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		~ClapTrap(void);
		ClapTrap& operator=(const ClapTrap& copy);
		
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		void		setEnergyPoint(int amount);
		void		setHitPoint(int amount);
		void		setAttackDmg(int amount);
		void		setName(std::string name);
		int			getEnergyPoint() const;
		int			getAttackDmg() const;
		int			getHitPoint() const;
		std::string getName() const;
		void		showInfo() const;

	protected:
		std::string 	_name;
		unsigned int 	_hit_point;
		unsigned int	_energy_point;
		unsigned int	_attack_damage;
		unsigned int 	_max_hit_point;
};

#endif