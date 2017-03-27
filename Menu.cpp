#include <iostream>
#include "Menu.h"

Menu::Menu(FilmDatabase& filmDB) : db(filmDB)
{
}

void Menu::mainMenu()
{
	std::cout << "\t _____ _ _               \n"
		 	  << "\t|  ___(_) |_ __ ___  ____\n"
		  	  << "\t| |_  | | | '_ ` _ \\|_  /\n"
		      << "\t|  _| | | | | | | | |/ / \n"
		      << "\t|_|   |_|_|_| |_| |_/___|\n\n"
			  << "\tBrowsing Titles Has Never Been Easier\n\n\n";
			                          

	char input;
	bool continueBrowsing = true;

	do
	{
		std::cout << "\n\t\tM A I N\tM E N U\n\n"
				  << "\tA - About the Application\n"
	  			  << "\tR - Reports\n"
	  			  << "\tS - Search the Database\n"
	  			  << "\tX - Exit the Program\n\n"
	  			  << "\tEnter Selection -> ";

		std::cin >> input;

		if (input == 'a' || input == 'A')
		{
			aboutApplication();
		}
		else if (input == 'r' || input == 'R')
		{
			reportMenu();
		}
		else if (input == 's' || input == 'S')
		{
			searchMenu();
		}
		else if (input == 'x' || input == 'X')
		{
			std::cout << "\n\n\tGOODBYE!\n\n";
			continueBrowsing = false;
		}
		else
		{
			std::cout << "\n\n\tYou have entered an incorrent value.\n"
					  << "Please Enter: 'A', 'R', 'S', or 'X'\n\n";
		}
		std::cout << "\n\n\n\n\n\n\n";
	}
	while(continueBrowsing);
	
}

void Menu::aboutApplication()
{
	std::cout << "\n\n\tAbout this application...\n\n"
			  << "\tPress any key to continue...\n\n";

	std::cin.get();
	std::cin.ignore();
}

void Menu::reportMenu()
{
	std::cout << "\n\n\tReport Menu...\n\n"
		      << "\tPress any key to continue...\n\n";
	          
	std::cin.get();
	std::cin.ignore();
}

void Menu::searchMenu()
{
	std::cout << "\n\n\tSearch Menu...\n\n"
			  << "\tPress any key to continue...\n\n";
	          
	std::cin.get();
	std::cin.ignore();
}
