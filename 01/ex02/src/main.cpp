/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:15 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 14:04:56 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	// Variable string initialisée
	std::string brain = "HI THIS IS BRAIN";

	// Pointeur sur la variable
	std::string *stringPTR = &brain;

	// Référence sur la variable
	std::string &stringREF = brain;

	// Affichage des adresses mémoire
	std::cout << "Adresse de la variable brain: " << &brain << std::endl;
	std::cout << "Adresse contenue dans stringPTR: " << stringPTR << std::endl;
	std::cout << "Adresse référencée par stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	// Affichage des valeurs
	std::cout << "Valeur de la variable brain: " << brain << std::endl;
	std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur référencée par stringREF: " << stringREF << std::endl;

	return (0);
}
