/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:27 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 13:47:45 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void announce(void) const;
	void setName(const std::string &name);
};

// Fonction qui alloue un Zombie sur le tas (heap)
Zombie	*newZombie(std::string name);

// Fonction qui crée un Zombie sur la pile et le fait annoncer immédiatement
void	randomChump(std::string name);

Zombie	*zombieHorde(int N, std::string name);

#endif
