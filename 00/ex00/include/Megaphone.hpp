/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:26:58 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 16:37:41 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP

# include <cctype>
# include <iostream>
# include <string>

class Megaphone
{
  public:
	Megaphone();

	// Méthode qui convertit une chaîne en majuscules
	std::string convertToUpper(const std::string &input);

	// Méthode qui traite les arguments de la ligne de commande
	void process(int argc, char **argv);
};

#endif
