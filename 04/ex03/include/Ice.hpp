/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:24:10 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/31 14:24:13 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice();

	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);
};

#endif
