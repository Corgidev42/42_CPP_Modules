/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:11:36 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 15:32:17 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type){}
Weapon::~Weapon(){}

const std::string	&Weapon::getType() const{
	return (_type);
}


void				Weapon::setType(const std::string &newType){
	_type = newType;
}

