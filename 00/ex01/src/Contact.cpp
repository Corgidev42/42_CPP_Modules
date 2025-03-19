/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:54:55 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 18:18:53 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void		Contact::displayDetails() const
{
	std::cout << "First Name: " << firstName_ << std::endl;
	std::cout << "Last Name: " << lastName_ << std::endl;
	std::cout << "Nickname: " << nickname_ << std::endl;
	std::cout << "Phone Number: " << phoneNumber_ << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret_ << std::endl;
}

void		Contact::setContactInfo(const std::string &firstName,
	const std::string &lastName,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &darkestSecret)
{
	firstName_ = firstName;
	lastName_ = lastName;
	nickname_ = nickname;
	phoneNumber_ = phoneNumber;
	darkestSecret_ = darkestSecret;
}

void		Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << "|"
	<< std::setw(10) << truncateAttribute(firstName_) << "|"
	<< std::setw(10) << truncateAttribute(lastName_) << "|"
	<< std::setw(10) << truncateAttribute(nickname_) << "|" << std::endl;
}

std::string	Contact::truncateAttribute(std::string attribute) const
{
	std::string truncatedAttribute;

	if (attribute.size() > 10)
	{
		truncatedAttribute = attribute.substr(0, 9);
		truncatedAttribute = truncatedAttribute.append(".");
		return (truncatedAttribute);
	}

	return (attribute);
}
