/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:25:51 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:26:08 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
	std::cout << "===== MateriaSource and Character Test =====" << std::endl;

	// Création d'une MateriaSource et apprentissage des Materias Ice et Cure
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Création d'un personnage "me"
	ICharacter* me = new Character("me");

	// Création et équipement de Materia via MateriaSource
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	// Création d'un second personnage "bob"
	ICharacter* bob = new Character("bob");

	// Utilisation des Materias équipées
	me->use(0, *bob);
	me->use(1, *bob);

	// Test de l'opérateur unequip (on peut par exemple détacher la première materia)
	me->unequip(0);

	// Tentative d'utilisation après unequip
	me->use(0, *bob); // Ne devrait rien faire

	// Libération de la mémoire
	delete bob;
	delete me;
	delete src;

	return 0;
}
