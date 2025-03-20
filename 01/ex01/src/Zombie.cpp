/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:31 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 13:52:26 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : _name("defaultZombie"){
    std::cout << "A Zombie has been created with the default name: " << _name << std::endl;
};

Zombie::Zombie(const std::string &name) : _name(name){
	std::cout << "Braiiiiiiinnnzzz... " << _name << " has risen from the grave!" << std::endl;
}

Zombie::~Zombie(){
	std::cout << _name << " is being destroyed" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	_name = name;
}

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}
Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (nullptr);

	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N ; i++)
		horde[i].setName(name);
	return (horde);
}

