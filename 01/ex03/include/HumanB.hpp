/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:08:47 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 15:27:12 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class Weapon;

class HumanB{
	private:
	std::string	_name;
	Weapon		*_weapon;

	public:
	HumanB(const std::string name);
	~HumanB();

	void	attack() const;
	void	setWeapon(Weapon &weapon);
};

#endif
