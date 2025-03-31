/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_is_for_losers.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbonnard <vbonnard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:13:34 by vbonnard          #+#    #+#             */
/*   Updated: 2025/03/26 11:13:35 by vbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
	// Vérification du nombre d'arguments
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);

	// Vérifie que s1 n'est pas vide (sinon, remplacement impossible)
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty." << std::endl;
		return 1;
	}

	// Ouverture du fichier source en lecture
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return 1;
	}

	// Lecture du contenu du fichier dans une chaîne
	std::stringstream buffer;
	buffer << infile.rdbuf();
	std::string content = buffer.str();
	infile.close();

	// Remplacement de toutes les occurrences de s1 par s2
	std::string result;
	size_t pos = 0;
	while (true)
	{
		size_t found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			result += content.substr(pos);
			break;
		}
		// Ajoute la partie avant s1
		result += content.substr(pos, found - pos);
		// Ajoute s2 à la place de s1
		result += s2;
		// Passe à la suite après s1
		pos = found + s1.length();
	}

	// Création du nom du fichier de sortie : "<filename>.replace"
	std::string outFilename = filename + ".replace";

	// Ouverture du fichier de sortie en écriture
	std::ofstream outfile(outFilename.c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not create output file " << outFilename << std::endl;
		return 1;
	}

	// Écriture du résultat dans le fichier de sortie
	outfile << result;
	outfile.close();

	return 0;
}
