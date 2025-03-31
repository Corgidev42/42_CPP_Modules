/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:06:49 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:18:34 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// DiamondTrap hérite de FragTrap et ScavTrap.
// FragTrap et ScavTrap doivent hériter virtuellement de ClapTrap pour n'avoir qu'une seule instance.
class DiamondTrap : public FragTrap, public ScavTrap {
private:
	std::string _name; // Nom propre de DiamondTrap (même nom que dans ClapTrap)
public:
	// Constructeur prenant le nom en paramètre
	DiamondTrap(const std::string &name);
	// Constructeur de recopie
	DiamondTrap(const DiamondTrap &other);
	// Opérateur d'affectation
	DiamondTrap &operator=(const DiamondTrap &other);
	// Destructeur
	~DiamondTrap();

	// Override pour résoudre l'ambiguïté sur attack()
	virtual void attack(const std::string &target);

	// Méthode spéciale qui affiche le nom propre et le nom du sous-objet ClapTrap
	void whoAmI();
};

#endif
