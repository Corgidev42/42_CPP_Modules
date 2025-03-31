/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:24:37 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:38 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other) {
	std::cout << "Cure copy constructor called." << std::endl;
}

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure copy assignment operator called." << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Cure::~Cure() {
	std::cout << "Cure destructor called." << std::endl;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
