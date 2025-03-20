/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:26:31 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 13:44:59 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string &name) : _name(name){
	std::cout << "Braiiiiiiinnnzzz... " << _name << " has risen from the grave!" << std::endl;
}

Zombie::~Zombie(){
	std::cout << _name << " is being destroyed" << std::endl;
}

void	Zombie::announce(void) const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
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
