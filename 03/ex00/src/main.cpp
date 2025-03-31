/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:45:35 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:45:38 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap robot("CL4P-TP");

	robot.attack("target_dummy");
	robot.takeDamage(3);
	robot.beRepaired(5);

	// Création d'une copie via le constructeur de recopie
	ClapTrap copyRobot(robot);
	copyRobot.attack("another_target");

	// Test de l'opérateur d'affectation
	ClapTrap assignedRobot("Default");
	assignedRobot = robot;
	assignedRobot.takeDamage(2);

	return 0;
}
