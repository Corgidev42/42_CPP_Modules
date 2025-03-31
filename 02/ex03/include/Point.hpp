/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:25:28 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	const Fixed _x;
	const Fixed _y;
public:
	// Constructeur par défaut qui initialise x et y à 0
	Point();
	// Constructeur qui prend deux float pour initialiser x et y
	Point(const float x, const float y);
	// Constructeur de recopie
	Point(const Point &other);
	// Opérateur d'affectation (ne modifie rien car les membres sont const)
	Point &operator=(const Point &other);
	// Destructeur
	~Point();

	// Accesseurs
	Fixed getX() const;
	Fixed getY() const;
};

#endif
