/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:07:26 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:14:42 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructeur par défaut
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Constructeur de recopie
Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Opérateur d'affectation
Fixed			&Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return *this;
}

// Destructeur
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Méthode d'accès
int				Fixed::getRawBits(void) const {
	// Message pour le débogage
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void			Fixed::setRawBits(int const raw) {
	_value = raw;
}

// Constructeur prenant un int
Fixed::Fixed(const int intVal) {
	std::cout << "Int constructor called" << std::endl;
	_value = intVal << _fractBits; // Multiplie par 256
}

// Constructeur prenant un float
Fixed::Fixed(const float floatVal) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(floatVal * (1 << _fractBits)); // Multiplie par 256 et arrondit
}

// Conversion en float
float			Fixed::toFloat(void) const {
	return static_cast<float>(_value) / (1 << _fractBits);
}

// Conversion en int
int				Fixed::toInt(void) const {
	return _value >> _fractBits;
}

// Opérateurs de comparaison

bool			Fixed::operator>(const Fixed &other) const
{
	return _value > other._value;
}

bool			Fixed::operator<(const Fixed &other) const
{
	return _value < other._value;
}

bool			Fixed::operator>=(const Fixed &other) const
{
	 return _value >= other._value;
}

bool			Fixed::operator<=(const Fixed &other) const
{
	 return _value <= other._value;
}

bool			Fixed::operator==(const Fixed &other) const
{
	 return _value == other._value;
}

bool			Fixed::operator!=(const Fixed &other) const
{
	 return _value != other._value;
}

// Opérateurs arithmétiques
Fixed			Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_value + other._value);
	return result;
}

Fixed			Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(_value - other._value);
	return result;
}

Fixed			Fixed::operator*(const Fixed &other) const {
	Fixed result;
	// La multiplication doit ajuster la valeur par rapport aux bits fractionnaires
	long temp = static_cast<long>(_value) * other._value;
	result.setRawBits(static_cast<int>(temp >> _fractBits));
	return result;
}

Fixed			Fixed::operator/(const Fixed &other) const {
	Fixed result;
	if (other._value != 0) {
		// Pour la division, décaler _value à gauche avant de diviser
		long temp = (static_cast<long>(_value) << _fractBits) / other._value;
		result.setRawBits(static_cast<int>(temp));
	}
	// Si division par 0, le comportement n'est pas défini (le programme peut crash)
	return result;
}

// Opérateurs d'incrémentation et de décrémentation

// Pré-incrémentation
Fixed			&Fixed::operator++() {
	++_value;
	return *this;
}

// Post-incrémentation
Fixed			Fixed::operator++(int) {
	Fixed temp(*this);
	_value++;
	return temp;
}

// Pré-décrémentation
Fixed			&Fixed::operator--() {
	--_value;
	return *this;
}

// Post-décrémentation
Fixed			Fixed::operator--(int) {
	Fixed temp(*this);
	_value--;
	return temp;
}

// Fonctions statiques min et max

Fixed			&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return b;
}

const			Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return a;
	return b;
}

Fixed			&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return b;
}

const Fixed		&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return a;
	return b;
}

// Surcharge de l'opérateur <<
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
