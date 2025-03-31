/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:21:41 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:37:57 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string _type;
public:
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const & getType() const; // Retourne le type

	virtual AMateria* clone() const = 0;  // Méthode pure virtuelle
	virtual void use(ICharacter& target); // Peut être surchargée
};

#endif
