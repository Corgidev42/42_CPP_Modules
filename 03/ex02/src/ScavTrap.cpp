/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:51:51 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:51:54 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructeur : appel de la base puis initialisation des nouvelles valeurs
ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name) {
	// Redéfinir les attributs pour ScavTrap
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " created with "
			<< _hitPoints << " hit points, "
			<< _energyPoints << " energy points, and "
			<< _attackDamage << " attack damage." << std::endl;
}

// Constructeur de recopie
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called for " << _name << std::endl;
}

// Opérateur d’affectation
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructeur
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is being destroyed." << std::endl;
}

// Redéfinition de attack pour ScavTrap
void ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ScavTrap " << _name
				<< " cannot attack because it has no hit points or energy left."
				<< std::endl;
		return;
	}
	_energyPoints--; // Coût de l'attaque
	std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

// Méthode spécifique à ScavTrap
void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}
