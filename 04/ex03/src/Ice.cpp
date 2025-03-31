/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:24:20 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:21 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other) {
	std::cout << "Ice copy constructor called." << std::endl;
}

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice copy assignment operator called." << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

Ice::~Ice() {
	std::cout << "Ice destructor called." << std::endl;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
