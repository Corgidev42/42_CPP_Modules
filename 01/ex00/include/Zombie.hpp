/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 13:45:43 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
	/* data */
	std::string _name;
public:
	Zombie(const std::string &name);
	~Zombie();

	void announce(void) const;
};

// Fonction qui alloue un Zombie sur le tas (heap)
Zombie* newZombie(std::string name);

// Fonction qui crée un Zombie sur la pile et le fait annoncer immédiatement
void randomChump(std::string name);

#endif
