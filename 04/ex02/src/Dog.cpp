/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:50:48 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:50:49 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()) {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain)) {
	std::cout << "Dog copy constructor called" << std::endl;
	type = other.type;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
		type = other.type;
	}
	return *this;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
