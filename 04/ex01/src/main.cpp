/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:51:57 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:52:03 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	const int n = 4;
	Animal* animals[n];

	// Créer un tableau d'Animal* avec la moitié de Dogs et la moitié de Cats
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n=== Les animaux font leur bruit ===" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}

	// Test de copie profonde pour Dog
	std::cout << "\n=== Test de copie profonde pour Dog ===" << std::endl;
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog(*dog1);  // Constructeur de recopie
	std::cout << "Original Dog type: " << dog1->getType() << std::endl;
	dog1->makeSound();
	std::cout << "Copied Dog type: " << dog2->getType() << std::endl;
	dog2->makeSound();
	delete dog1;
	delete dog2;

	// Libération de la mémoire pour le tableau d'Animal*
	std::cout << "\n=== Suppression du tableau d'animaux ===" << std::endl;
	for (int i = 0; i < n; i++) {
		delete animals[i];
	}

	return 0;
}
