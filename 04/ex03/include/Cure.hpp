/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:24:29 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:30 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
