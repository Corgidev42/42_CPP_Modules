/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:01:19 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:01:23 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
	std::cout << "===== Création dynamique d'animaux =====" << std::endl;

	// Création dynamique via Animal* (polymorphisme)
	const Animal* dog1 = new Dog();
	const Animal* cat1 = new Cat();

	std::cout << "\n-- Affichage du type et du son (polymorphisme) --" << std::endl;
	std::cout << "dog1 type: " << dog1->getType() << std::endl;
	std::cout << "dog1 sound: ";
	dog1->makeSound();

	std::cout << "cat1 type: " << cat1->getType() << std::endl;
	std::cout << "cat1 sound: ";
	cat1->makeSound();

	std::cout << "\n===== Test du constructeur de recopie pour Dog =====" << std::endl;
	Dog* originalDog = new Dog();
	Dog* copyDog = new Dog(*originalDog);  // appel du constructeur de recopie
	std::cout << "Original Dog type: " << originalDog->getType() << std::endl;
	std::cout << "Original Dog sound: ";
	originalDog->makeSound();
	std::cout << "Copied Dog type: " << copyDog->getType() << std::endl;
	std::cout << "Copied Dog sound: ";
	copyDog->makeSound();

	std::cout << "\n===== Test de l'opérateur d'affectation pour Cat =====" << std::endl;
	Cat* catA = new Cat();
	Cat* catB = new Cat();
	std::cout << "Avant affectation:" << std::endl;
	std::cout << "catA type: " << catA->getType() << std::endl;
	std::cout << "catB type: " << catB->getType() << std::endl;

	*catB = *catA; // affectation par opérateur =

	std::cout << "Après affectation:" << std::endl;
	std::cout << "catA type: " << catA->getType() << std::endl;
	std::cout << "catB type: " << catB->getType() << std::endl;
	std::cout << "catB sound: ";
	catB->makeSound();

	std::cout << "\n===== Fin du test, destruction des objets =====" << std::endl;

	// Libération de la mémoire
	delete dog1;
	delete cat1;
	delete originalDog;
	delete copyDog;
	delete catA;
	delete catB;

	std::cout << "\n===== Fin du programme =====" << std::endl;
	return 0;
}
