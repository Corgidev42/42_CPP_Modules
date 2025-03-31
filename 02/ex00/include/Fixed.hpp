/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:22:57 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 12:23:03 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int         _value;
	static const int _fractBits = 8;
public:
	// Constructeur par défaut
	Fixed();
	// Constructeur de recopie
	Fixed(const Fixed &other);
	// Opérateur d’affectation
	Fixed &operator=(const Fixed &other);
	// Destructeur
	~Fixed();

	// Retourne la valeur brute du nombre à virgule fixe
	int getRawBits(void) const;
	// Affecte une valeur brute à l'objet
	void setRawBits(int const raw);
};

#endif
