/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:06:16 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:06:41 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_value;
	static const int	_fractBits = 8;
public:
	// Forme canonique
	Fixed();								// Constructeur par défaut
	Fixed(const Fixed &other);				// Constructeur de recopie
	Fixed &operator=(const Fixed &other);	// Opérateur d'affectation
	~Fixed();								// Destructeur

	// Méthodes de base
	int getRawBits(void) const;
	void setRawBits(int const raw);

	// Constructeurs supplémentaires
	Fixed(const int intVal);
	Fixed(const float floatVal);

	// Conversion
	float toFloat(void) const;
	int toInt(void) const;

	// Opérateurs de comparaison
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	// Opérateurs arithmétiques
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	// Incrémentation / Décrémentation
	Fixed &operator++();   // Pré-incrémentation
	Fixed operator++(int); // Post-incrémentation
	Fixed &operator--();   // Pré-décrémentation
	Fixed operator--(int); // Post-décrémentation

	// Fonctions statiques min et max (version non const et const)
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Surcharge de l'opérateur d'insertion
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
