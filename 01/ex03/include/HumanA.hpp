/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:04:53 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/20 15:28:05 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class Weapon;

class HumanA{

	private:
	std::string	_name;
	Weapon		&_weapon;

	public:
	HumanA(const std::string &name, Weapon &weapon);
	~HumanA();

	void	attack() const;
};

#endif
