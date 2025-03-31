/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:07:02 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 13:16:04 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

# include <string>
# include <iostream>
# include <ostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	// Constructeur qui prend le nom en paramètre
	FragTrap(const std::string &name);
	// Constructeur de recopie
	FragTrap(const FragTrap &other);
	// Opérateur d'affectation
	FragTrap &operator=(const FragTrap &other);
	// Destructeur
	~FragTrap();

	// Redéfinition (optionnelle) de attack si besoin d'un message spécifique
	void	attack(const std::string &target);
	// Méthode spécifique de FragTrap
	void	highFivesGuys(void);
};

#endif
