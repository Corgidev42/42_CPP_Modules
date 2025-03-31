/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMeteria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:22:02 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:22:04 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria of type " << _type << " constructed." << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type) {
	std::cout << "AMateria copy constructor called." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other) {
	std::cout << "AMateria copy assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "AMateria of type " << _type << " destructed." << std::endl;
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	// Par défaut, ne fait rien (ou affiche un message générique)
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
