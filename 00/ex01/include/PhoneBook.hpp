/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:54:58 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 18:19:32 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <string>
# include <iostream>
# include "Contact.hpp"
# include <sstream>

class PhoneBook
{
  public:
			PhoneBook();

	// Méthode pour ajouter un nouveau contact
	void	addContact();

	// Méthode pour afficher la liste des contacts (formatée)
	void	searchContacts() const;

	// Méthode pour afficher les détails d'un contact donné par son index
	void	displayContactDetails(int index) const;

  private:
	static const	int maxContacts_ = 8;
	Contact			contacts_[maxContacts_];
	int				totalContacts_;
};

#endif
