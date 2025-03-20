/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:11:10 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:42 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): _name(name), _weapon(weapon){}
HumanA::~HumanA(){}

void	HumanA::attack() const{
	std::cout << _name << " attaque avec son " << _weapon.getType() << std::endl;
}
