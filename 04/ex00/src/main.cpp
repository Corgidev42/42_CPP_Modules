/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:40:52 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:43:32 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
	std::cout << "=== Test des classes Animal, Dog et Cat ===" << std::endl;

	// Création dynamique via des pointeurs de type Animal*
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "Type de dog : " << dog->getType() << std::endl;
	std::cout << "Type de cat : " << cat->getType() << std::endl;

	std::cout << "Appel de makeSound() sur meta (Animal) : ";
	meta->makeSound();
	std::cout << "Appel de makeSound() sur dog (Dog) : ";
	dog->makeSound();
	std::cout << "Appel de makeSound() sur cat (Cat) : ";
	cat->makeSound();

	// Test de copie (constructeur de recopie) pour Dog
	std::cout << "\n=== Test du constructeur de recopie pour Dog ===" << std::endl;
	Dog* dogCopy = new Dog(*(dynamic_cast<const Dog*>(dog)));
	std::cout << "Type du chien copié : " << dogCopy->getType() << std::endl;
	dogCopy->makeSound();

	// Test de l'opérateur d'affectation pour Cat
	std::cout << "\n=== Test de l'opérateur d'affectation pour Cat ===" << std::endl;
	Cat catAssign;
	catAssign = *(dynamic_cast<const Cat*>(cat));
	std::cout << "Type du chat assigné : " << catAssign.getType() << std::endl;
	catAssign.makeSound();

	// Libération de la mémoire allouée dynamiquement
	delete meta;
	delete dog;
	delete cat;
	delete dogCopy;

	std::cout << "\n=== Test des classes WrongAnimal et WrongCat ===" << std::endl;

	// Création dynamique pour les WrongAnimal
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Type de wrongCat : " << wrongCat->getType() << std::endl;

	std::cout << "Appel de makeSound() sur wrongAnimal : ";
	wrongAnimal->makeSound();
	std::cout << "Appel de makeSound() sur wrongCat : ";
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
