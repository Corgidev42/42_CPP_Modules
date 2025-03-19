/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 17:00:29 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 18:19:06 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact
{
  public:
	// Constructeur par défaut qui initialise avec des valeurs par défaut
	Contact() : firstName_("John"), lastName_("Doe"), nickname_("JD"),
		phoneNumber_("0000000000"), darkestSecret_("No secret")
	{
	}

	// Constructeur pour initialiser avec des valeurs spécifiques
	Contact(const std::string &firstName, const std::string &lastName,
		const std::string &nickname, const std::string &phoneNumber,
		const std::string &darkestSecret) : firstName_(firstName),
		lastName_(lastName), nickname_(nickname), phoneNumber_(phoneNumber),
		darkestSecret_(darkestSecret)
	{
	}

	// Méthode pour remplir les informations du contact (via des setters ou une méthode unique)
	void setContactInfo(const std::string &firstName,
		const std::string &lastName, const std::string &nickname,
		const std::string &phoneNumber, const std::string &darkestSecret);

	// Autres méthodes pour afficher les infos, etc.
	void displayDetails() const;

	// Méthode pour afficher le résumé (pour la recherche)
	void displaySummary(int index) const;

  private:
	std::string firstName_;
	std::string lastName_;
	std::string nickname_;
	std::string phoneNumber_;
	std::string darkestSecret_;

	// Méthode pour troncker en summary les attributs
	std::string	truncateAttribute(std::string attribute) const;
};

#endif
