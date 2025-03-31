/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:26:21 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:26:27 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

// Fonction locale pour calculer l'aire signée du triangle formé par trois points
static float area(Point const a, Point const b, Point const c) {
	// Utilisation des coordonnées converties en float
	return (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
		+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
		+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat())) / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	// Calcul des aires en valeur absolue
	float A = fabs(area(a, b, c));
	float A1 = fabs(area(point, b, c));
	float A2 = fabs(area(a, point, c));
	float A3 = fabs(area(a, b, point));

	// Si le point est sur une arrête ou un sommet, l'une des aires sera pratiquement 0
	if (A1 < 0.0001f || A2 < 0.0001f || A3 < 0.0001f)
		return false;

	// Vérifie que la somme des aires des sous-triangles est égale à l'aire du triangle principal (tolérance pour float)
	return fabs(A - (A1 + A2 + A3)) < 0.0001f;
}
