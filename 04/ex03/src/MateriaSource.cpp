/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:42 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:25:43 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	std::cout << "MateriaSource copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	std::cout << "MateriaSource copy assignment operator called." << std::endl;
	if (this != &other) {
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

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == 0) {
			_inventory[i] = m->clone();
			std::cout << "Materia learned in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource inventory is full. Cannot learn more materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "MateriaSource creates a materia of type " << type << "." << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "MateriaSource has not learned a materia of type " << type << "." << std::endl;
	return 0;
}
