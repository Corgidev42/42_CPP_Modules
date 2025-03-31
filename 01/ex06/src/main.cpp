#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	// Vérifie qu'un argument est passé
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <level>" << std::endl;
		return 1;
	}

	std::string level(argv[1]);
	int index = -1;

	// Conversion du niveau en entier
	if (level == "DEBUG")
		index = 0;
	else if (level == "INFO")
		index = 1;
	else if (level == "WARNING")
		index = 2;
	else if (level == "ERROR")
		index = 3;

	Harl harl;

	switch (index) {
		case 0:
			harl.complain("DEBUG");
			std::cout << std::endl;
			// Fallthrough

		case 1:
			harl.complain("INFO");
			std::cout << std::endl;
			// Fallthrough
		case 2:
			harl.complain("WARNING");
			std::cout << std::endl;
			// Fallthrough
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

	return 0;
}
