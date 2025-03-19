/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:27:39 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/19 16:36:50 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Megaphone.hpp"

Megaphone::Megaphone()
{}

std::string Megaphone::convertToUpper(const std::string &input)
{
	std::string result = input;
	for (size_t i = 0; i < result.size(); ++i)
		result[i] = std::toupper(result[i]);
	return (result);
}

void	Megaphone::process(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return ;
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string argument = argv[i];
		std::cout << convertToUpper(argument);
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

int		main(int argc, char **argv)
{
	Megaphone megaphone;
	megaphone.process(argc, argv);
	return (0);
}
