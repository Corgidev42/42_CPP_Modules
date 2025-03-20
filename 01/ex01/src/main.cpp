/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:42:15 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 13:49:22 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int		N;
	Zombie	*horde;

	N = 5;
	std::string name = "HordeZombie";
	horde = zombieHorde(N, name);
	if (!horde)
	{
		std::cerr << "Allocation failed or invalid number of zombies." << std::endl;
		return (1);
	}
	// Faire annoncer tous les zombies
	for (int i = 0; i < N; i++)
		horde[i].announce();

	// Libère la mémoire allouée pour la horde
	delete[] horde;
	return (0);
}
