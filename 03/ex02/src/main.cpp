/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:07:39 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 15:16:29 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"



int main() {
	// Création d'une instance de FragTrap
	FragTrap frag("FR4G-TP");

	// Test de l'attaque (redéfinie dans FragTrap)
	frag.attack("target_dummy");

	// Test de la méthode spéciale highFivesGuys()
	frag.highFivesGuys();

	// Test du constructeur de recopie
	FragTrap copyFrag(frag);
	copyFrag.attack("another_target");

	return 0;
}
