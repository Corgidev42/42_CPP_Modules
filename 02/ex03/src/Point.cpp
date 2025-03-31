/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:25:56 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:26:07 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point		&Point::operator=(const Point &other) {
	// Les membres étant constants, on ne peut pas les modifier.
	(void)other;
	return *this;
}

Point::~Point() {}

Fixed		Point::getX() const {
	return _x;
}

Fixed		Point::getY() const {
	return _y;
}
