/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:40:05 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:40:06 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void separator(std::string title = "") {
	std::cout << "\n===== " << title << " =====\n" << std::endl;
}

int main() {
	separator("Création et apprentissage de Materias");

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	separator("Création d’un Character et équipement");

	ICharacter* me = new Character("me");
	AMateria* ice = src->createMateria("ice");
	AMateria* cure = src->createMateria("cure");
	AMateria* unknown = src->createMateria("fire"); // type non appris

	me->equip(ice);
	me->equip(cure);
	me->equip(unknown); // null, ne devrait rien faire

	separator("Tentative d’équipement plein");

	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice()); // devrait afficher "inventory full"

	separator("Création d’un autre personnage et test de use");

	ICharacter* bob = new Character("bob");

	me->use(0, *bob); // ice
	me->use(1, *bob); // cure
	me->use(2, *bob); // valide
	me->use(3, *bob); // valide
	me->use(4, *bob); // invalide

	separator("Test de unequip et re-use");

	me->unequip(1);
	me->use(1, *bob); // ne devrait rien faire

	separator("Test copie profonde de Character");

	Character original("source");
	original.equip(new Ice());
	original.equip(new Cure());

	Character copy(original); // appel du constructeur de copie
	copy.use(0, *bob); // ice
	copy.use(1, *bob); // cure

	separator("Test affectation entre deux Characters");

	Character assign1("A"), assign2("B");
	assign1.equip(new Cure());
	assign2 = assign1; // opérateur =
	assign2.use(0, *bob); // cure

	separator("Test copie profonde de MateriaSource");

	MateriaSource originalMS;
	originalMS.learnMateria(new Ice());
	originalMS.learnMateria(new Cure());

	MateriaSource copiedMS(originalMS);
	AMateria* copied = copiedMS.createMateria("cure");
	if (copied)
		copied->use(*bob);

	separator("Nettoyage");

	delete me;
	delete bob;
	delete src;
	delete unknown;
	delete copied;

	separator("Fin du test");

	return 0;
}
