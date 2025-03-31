/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:47:30 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:13:18 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed			&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int				Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void			Fixed::setRawBits(int const raw) {
	_value = raw;
}

// Constructeur qui prend un int et le convertit en virgule fixe
Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_value = intVal << _fractBits; // équivaut à intVal * 256
}

// Constructeur qui prend un float et le convertit en virgule fixe
Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatVal * (1 << _fractBits)); // floatVal * 256 arrondi
}

float			Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractBits);
}

int				Fixed::toInt(void) const {
	return _value >> _fractBits;
}

// Surcharge de l'opérateur <<
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
