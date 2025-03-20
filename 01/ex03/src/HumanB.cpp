/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:11:09 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:43 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(const std::string name): _name(name){}
HumanB::~HumanB(){}

void	HumanB::attack() const{
	if (_weapon)
		std::cout << _name << " attaque avec son/sa " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " n'a pas d'arme avec laquelle attaquer " << std::endl;
}
void	HumanB::setWeapon(Weapon &weapon){
	this->_weapon = &weapon;
}
