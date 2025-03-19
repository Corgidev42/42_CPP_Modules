/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 18:15:53 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 18:16:39 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	command;
	int			index;
	std::string	indexStr;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD")
		{
			phoneBook.addContact();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContacts();
			std::cout << "Enter index to display details: ";
			std::getline(std::cin, indexStr);

			std::istringstream iss(indexStr);
			if (!(iss >> index))
			{
				std::cout << "Invalid input. Please enter a number." << std::endl;
			}
			else
			{
				phoneBook.displayContactDetails(index);
			}
		}
		else if (command == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout << "Unknown command." << std::endl;
		}
	}

	return (0);
}
