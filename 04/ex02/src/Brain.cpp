/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:49:40 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:49:42 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
	// Initialisation par défaut de chaque idée
	for (int i = 0; i < 100; i++) {
		ideas[i] = "Default idea";
	}
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::printIdeas() const {
	std::cout << "Brain ideas: " << std::endl;
	for (int i = 0; i < 5; i++) { // Affiche les 5 premières idées pour tester
		std::cout << "- " << ideas[i] << std::endl;
	}
}
