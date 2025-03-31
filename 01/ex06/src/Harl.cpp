/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:30:30 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:12:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Définition des méthodes privées
void	Harl::debug(void) {
	std::cout << "[DEBUG]"  << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl() {}

Harl::~Harl() {}

// Utilisation des pointeurs vers fonctions membres
void	Harl::complain(std::string level) {
	// Définition du type pour un pointeur vers une fonction membre de Harl
	typedef void (Harl::*HarlMemFn)(void);

	// Tableau des niveaux et fonctions correspondantes
	const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlMemFn funcs[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	// Recherche du niveau correspondant
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*funcs[i])();
			return;
		}
	}
	// Si aucun niveau n'est trouvé, afficher un message par défaut
	std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}
