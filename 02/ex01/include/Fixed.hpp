/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:46:31 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:02:45 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int _value;
	static const int _fractBits = 8;
public:
	// Forme canonique de Coplien
	Fixed();								// Constructeur par défaut
	Fixed(const Fixed &other);				// Constructeur de recopie
	Fixed &operator=(const Fixed &other);	// Opérateur d'affectation
	~Fixed();								// Destructeur

	// Méthodes de base
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Nouveaux constructeurs pour initialiser Fixed avec un int ou un float
	Fixed(const int intVal);
	Fixed(const float floatVal);

	// Méthodes de conversion
	float toFloat(void) const;
	int toInt(void) const;
};

// Surcharge de l'opérateur d'insertion pour afficher l'objet Fixed
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
