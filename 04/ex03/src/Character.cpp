/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:14 by vbonnard          #+#    #+#             */
/*   Updated: 2025/04/01 20:56:45 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string &name) : _name(name) {
	std::cout << "Character " << _name << " constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &other) : _name(other._name) {
	std::cout << "Character copy constructor called for " << _name << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

Character &Character::operator=(const Character &other) {
	std::cout << "Character copy assignment operator called for " << _name << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character " << _name << " destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == 0) {
			_inventory[i] = m;
			std::cout << _name << " equipped materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full." << std::endl;
}

// void Character::unequip(int idx) {
// 	if (idx < 0 || idx >= 4 || _inventory[idx] == 0) {
// 		std::cout << "No materia to unequip at slot " << idx << "." << std::endl;
// 		return;
// 	}
// 	std::cout << _name << " unequips materia from slot " << idx << "." << std::endl;
// 	_inventory[idx] = 0;
// }

AMateria* Character::unequip(int idx) {
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return NULL;
	AMateria* tmp = _inventory[idx];
	_inventory[idx] = NULL;
	return tmp;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || _inventory[idx] == 0) {
		std::cout << "No materia to use at slot " << idx << "." << std::endl;
		return;
	}
	_inventory[idx]->use(target);
}
