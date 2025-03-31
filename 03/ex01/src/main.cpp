/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:52:25 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:52:28 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap scav("SC4V-TP");

	scav.attack("target_dummy");
	scav.takeDamage(20);
	scav.beRepaired(10);
	scav.guardGate();

	// Test du constructeur de recopie
	ScavTrap copyScav(scav);
	copyScav.attack("another_target");

	return 0;
}
