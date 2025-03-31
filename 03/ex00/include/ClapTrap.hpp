/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:39:59 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:43:38 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	// Constructeur prenant le nom en paramètre
	ClapTrap(const std::string &name);

	// Constructeur de recopie
	ClapTrap(const ClapTrap &other);

	// Opérateur d'affectation
	ClapTrap &operator=(const ClapTrap &other);

	// Destructeur
	~ClapTrap();

	// Méthodes d'action
	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif
