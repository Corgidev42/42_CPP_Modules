/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:50:28 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 12:52:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>
# include <iostream>
# include <ostream>
# include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
public:
	// Constructeur qui prend le nom en paramètre
	ScavTrap(const std::string &name);
	// Constructeur de recopie
	ScavTrap(const ScavTrap &other);
	// Opérateur d’affectation
	ScavTrap &operator=(const ScavTrap &other);
	// Destructeur
	~ScavTrap();

	// Redéfinition de attack
	void	attack(const std::string &target);
	// Méthode spécifique
	void	guardGate();
};

#endif
