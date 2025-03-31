/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:07:00 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 15:07:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructeur : appel du constructeur de la base puis initialisation des attributs spécifiques
FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	// Redéfinir les attributs pour FragTrap
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " created with "
			<< _hitPoints << " hit points, "
			<< _energyPoints << " energy points, and "
			<< _attackDamage << " attack damage." << std::endl;
}

// Constructeur de recopie
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << _name << std::endl;
}

// Opérateur d'affectation
FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructeur
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is being destroyed." << std::endl;
}

// Optionnel : Redéfinition de attack pour FragTrap (ici, on peut conserver le comportement hérité
// ou afficher un message différent)
void FragTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "FragTrap " << _name
				<< " cannot attack because it has no hit points or energy left."
				<< std::endl;
		return;
	}
	_energyPoints--; // Coût de l'attaque
	std::cout << "FragTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

// Méthode spécifique highFivesGuys
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " requests high fives! Positive vibes all around!" << std::endl;
}
