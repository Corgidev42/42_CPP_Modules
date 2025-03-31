/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:10:15 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:10:24 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) {
	// Création de quelques objets Fixed
	Fixed a;
	Fixed b(5);			// Constructeur int
	Fixed c(5.05f);		// Constructeur float
	Fixed d(10.10f);

	// Test des opérateurs arithmétiques
	Fixed sum = b + c;
	Fixed diff = d - b;
	Fixed prod = b * c;
	Fixed div = d / c;

	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "Sum (b + c) is " << sum << std::endl;
	std::cout << "Difference (d - b) is " << diff << std::endl;
	std::cout << "Product (b * c) is " << prod << std::endl;
	std::cout << "Division (d / c) is " << div << std::endl;

	// Test des opérateurs de comparaison
	if (b < c)
		std::cout << "b is less than c" << std::endl;
	else
		std::cout << "b is not less than c" << std::endl;

	// Test des opérateurs d'incrémentation/décrémentation
	std::cout << "a is " << a << std::endl;
	std::cout << "Pre-increment: " << ++a << std::endl;
	std::cout << "Post-increment: " << a++ << std::endl;
	std::cout << "After post-increment, a is " << a << std::endl;

	// Test des fonctions statiques min et max
	std::cout << "Min between b and c is " << Fixed::min(b, c) << std::endl;
	std::cout << "Max between b and c is " << Fixed::max(b, c) << std::endl;

	return 0;
}
