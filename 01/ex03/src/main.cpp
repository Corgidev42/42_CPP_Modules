/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:18:28 by vbonnard          #+#    #+#             */
/*   Updated: 2025/04/01 20:28:17 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

int	main(void)
{
	// Test avec HumanA : l'arme est passée dans le constructeur
	Weapon baguette("baguette magique");
	HumanA pierre("Michelle", baguette);
	HumanB jacques("Jacquie");
	pierre.attack(); // Affiche: Pierre attaque avec sa baguette magique
	// Changement du type d'arme
	baguette.setType("baguette de pain");
	pierre.attack(); // Affiche: Pierre attaque avec sa baguette de pain
	// Test avec HumanB : l'arme sera assignée plus tard
	Weapon croissant("croissant tranchant");

	jacques.attack();
	jacques.setWeapon(croissant);
	jacques.attack();
	croissant.setType("croissant au beurre");
	jacques.attack();

	return (0);
}
