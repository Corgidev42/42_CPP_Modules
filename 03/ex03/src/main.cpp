/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:07:43 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:10:20 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	// Test de DiamondTrap
	std::cout << "\n--- DiamondTrap Tests ---" << std::endl;
	DiamondTrap diamond("DI4M-TP");

	// Vérification des méthodes héritées
	diamond.attack("test_target");
	diamond.takeDamage(40);
	diamond.beRepaired(20);

	// Vérification de la méthode spécifique whoAmI()
	diamond.whoAmI();

	// Test du constructeur de recopie et de l'opérateur d'affectation
	DiamondTrap copyDiamond(diamond);
	copyDiamond.whoAmI();

	DiamondTrap assignedDiamond("Assigned");
	assignedDiamond = diamond;
	assignedDiamond.whoAmI();

	return 0;
}
