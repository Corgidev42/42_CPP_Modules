/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:54:53 by vbonnard          #+#    #+#             */
/*   Updated: 2025/04/01 20:16:41 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <algorithm>

PhoneBook::PhoneBook() : totalContacts_(0)
{};

void	PhoneBook::addContact()
{
	std::string	firstName, lastName, nickname, phoneNumber, darkSecret;
	int			index;

	std::cout << "Enter your First Name : ";
	std::getline(std::cin, firstName);
	if(firstName.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return;
	}

	std::cout << "Enter your Last Name : ";
	std::getline(std::cin, lastName);
	if(lastName.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return;
	}

	std::cout << "Enter your Nickname : ";
	std::getline(std::cin, nickname);
	if(nickname.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return;
	}

	std::cout << "Enter your Phone Number (digits only): ";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		std::cout << "Field must contain digits only and cannot be empty." << std::endl;
		return;
	}

	std::cout << "Enter your DARK SECRET !! : ";
	std::getline(std::cin, darkSecret);
	if(darkSecret.empty())
	{
		std::cout << "Field cannot be empty." << std::endl;
		return;
	}

	index = totalContacts_ % maxContacts_;
	contacts_[index].setContactInfo(firstName, lastName, nickname, phoneNumber, darkSecret);

	if (totalContacts_ < maxContacts_)
		totalContacts_++;

	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContacts() const
{
	if (totalContacts_ == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "|" << std::endl;

	for (int i = 0 ; i < totalContacts_ ; i++)
		contacts_[i].displaySummary(i);
}


void	PhoneBook::displayContactDetails(int index) const {
	if (index < 0 || index >= totalContacts_) {
		std::cout << "Invalid index." << std::endl;
		return;
	}
	contacts_[index].displayDetails();
}

