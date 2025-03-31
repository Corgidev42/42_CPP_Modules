/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:26:41 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 14:34:13 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

// Déclaration de bsp
bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	// Création d'un triangle ABC
	Point A(0.0f, 0.0f);
	Point B(10.0f, 0.0f);
	Point C(0.0f, 10.0f);

	// Test avec un point strictement à l'intérieur
	Point P(3.0f, 3.0f);
	// Test avec un point en dehors
	Point Q(10.0f, 10.0f);
	// Test avec un point sur une arrête (ici, sur AB)
	Point R(5.0f, 0.0f);
	// Test avec un point sur une arrête (ici, sur AC)
	Point S(0.0f, 5.0f);
	// Test avec un point sur une arrête (ici, sur BC)
	Point T(5.0f, 5.0f);
	// Test avec un point au sommet A
	Point U(0.0f, 0.0f);
	// Test avec un point au sommet B
	Point V(10.0f, 0.0f);
	// Test avec un point au sommet C
	Point W(0.0f, 10.0f);

	std::cout << "Point P is " << (bsp(A, B, C, P) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point Q is " << (bsp(A, B, C, Q) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point R is " << (bsp(A, B, C, R) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point S is " << (bsp(A, B, C, S) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point T is " << (bsp(A, B, C, T) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point U is " << (bsp(A, B, C, U) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point V is " << (bsp(A, B, C, V) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;
	std::cout << "Point W is " << (bsp(A, B, C, W) ? "inside" : "NOT inside") << " the triangle ABC." << std::endl;

	return 0;
}
