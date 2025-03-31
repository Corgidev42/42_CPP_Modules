/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:43:46 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:43:48 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructeur principal
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " created with "
			<< _hitPoints << " hit points, "
			<< _energyPoints << " energy points, and "
			<< _attackDamage << " attack damage." << std::endl;
}

// Constructeur de recopie
ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout << "ClapTrap copy constructor called for " << _name << std::endl;
}

// Opérateur d'affectation
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		// Les attributs de type std::string et int se gèrent naturellement
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructeur
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " is being destroyed." << std::endl;
}

// Méthode attack
void ClapTrap::attack(const std::string &target) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name
				<< " cannot attack because it has no hit points or energy left."
				<< std::endl;
		return;
	}
	_energyPoints--; // Coût de l'attaque
	std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

// Méthode takeDamage
void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name << " is already out of hit points."
				<< std::endl;
		return;
	}
	_hitPoints -= amount;
	if (_hitPoints < 0)
		_hitPoints = 0;
	std::cout << "ClapTrap " << _name << " takes " << amount
			<< " points of damage! Remaining hit points: " << _hitPoints
			<< std::endl;
}

// Méthode beRepaired
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << "ClapTrap " << _name
				<< " cannot be repaired because it has no hit points or energy left."
				<< std::endl;
		return;
	}
	_energyPoints--; // Coût de la réparation
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, regaining "
			<< amount << " hit points! New hit points: " << _hitPoints
			<< std::endl;
}
