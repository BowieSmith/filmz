#include <iostream>
#include "Menu.h"

Menu::Menu(FilmDatabase& filmDB) : db(filmDB)
{
}

void Menu::mainMenu()
{
	std::cout << "\n\n\n" << std::endl;
	std::cout << "\t _____ _ _               \n"
		 	  << "\t|  ___(_) |_ __ ___  ____\n"
		  	  << "\t| |_  | | | '_ ` _ \\|_  /\n"
		      << "\t|  _| | | | | | | | |/ / \n"
		      << "\t|_|   |_|_|_| |_| |_/___|\n\n"
			  << "\t     Browsing Titles\n"
			  << "\t        Made Easy\n\n\n";
			                          

	char input;
	bool continueBrowsing = true;

	do
	{
		std::cout << "\n\t    M A I N    M E N U\n\n"
				  << "\tA - About the Application\n"
	  			  << "\tR - Reports\n"
	  			  << "\tS - Search the Database\n"
	  			  << "\tX - Exit the Program\n\n"
	  			  << "\tEnter Selection -> ";

		std::cin >> input;
		std::cout << "\n\n\n" << std::endl;

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
			std::cout << "\n\n\n\n\tGOODBYE!\n\n\n";
			continueBrowsing = false;
		}
		else
		{
			std::cout << "\n\n\tYou have entered an incorrent value.\n"
					  << "\tPlease Enter: 'A', 'R', 'S', or 'X'\n\n";
		}
	}
	while(continueBrowsing);
	
}

void Menu::aboutApplication()
{
	std::cout << "\n\n\tAbout this application...\n\n"
			  << "\tPress ENTER to continue...\n\n";

	std::cin.get();
	std::cin.ignore();

	std::cout << "\n\n\n\n";
}

void Menu::reportMenu()
{
	char input;
	bool continueBrowsing = true;

	do
	{
		std::cout << "\n\t    R E P O R T S    M E N U\n\n"
				  << "\tT - Order by Film Title report\n"
	  			  << "\tR - Order by Rank report\n"
	  			  << "\tX - Exit to Main Menu\n\n"
	  			  << "\tEnter Selection -> ";

		std::cin >> input;

		if (input == 't' || input == 'T')
		{
			db.displayReport("title");
		}
		else if (input == 'r' || input == 'R')
		{
			db.displayReport("rank");
		}
		else if (input == 'x' || input == 'X')
		{
			continueBrowsing = false;
			std::cout << "\n\n\n\n";
		}
		else
		{
			std::cout << "\n\n\tYou have entered an incorrent value.\n"
					  << "\tPlease Enter: 'T', 'R', or 'X'\n\n";
		}
		std::cout << "\n\n\n\n";
	}
	while(continueBrowsing);
}
void Menu::searchMenu()
{
	char input;
	bool continueBrowsing = true;
	std::string queryString;

	do
	{
		std::cout << "\n\t    S E A R C H    M E N U\n\n"
				  << "\tT - Search by Title\n"
	  			  << "\tK - Search by Keyword(s)\n"
	  			  << "\tS - Search by Studio\n"
	  			  << "\tM - Search by Month of Release\n"
				  << "\tX - Return to Main Menu\n\n"
	  			  << "\tEnter Selection -> ";

		std::cin >> input;

		if (input == 't' || input == 'T')
		{
			std::cout << "\n\n\tEnter an exact movie title to search for.\n"
					  << "\n\t-> ";
			std::cin.ignore();
			std::getline(std::cin,queryString);
			db.displaySearch("title",queryString);
		}
		else if (input == 'k' || input == 'K')
		{
			std::cout << "\n\n\tEnter one or more keywords to search for in movie titles.\n"
					  << "\tFor multiple keywords, use the form \"keyword1,keyword2,keyword3\"\n"
					  << "\n\t-> ";
			std::cin.ignore();
			std::getline(std::cin,queryString);
			db.displaySearch("keywords",queryString);
		}
		else if (input == 's' || input == 'S')
		{
			std::cout << "\n\n\tEnter the exact name of the studio to search for.\n"
					  << "\n\t-> ";
			std::cin.ignore();
			std::getline(std::cin,queryString);
			db.displaySearch("studio",queryString);
		}
		else if (input == 'm' || input == 'M')
		{
			std::cout << "\n\n\tEnter the month of release you are searching for.\n"
					  << "\tUse the values 1-12, where 1-Jan, 2-Feb, etc.\n"
					  << "\n\t-> ";
			std::cin.ignore();
			std::getline(std::cin,queryString);

			try
			{
				db.displaySearch("month",queryString);
			}
			catch (PrecondViolatedExcep e)
			{
				std::cout << e.what();
			}
		}
		else if (input == 'x' || input == 'X')
		{
			continueBrowsing = false;
		}
		else
		{
			std::cout << "\n\n\tYou have entered an incorrent value.\n"
					  << "\tPlease Enter: 'T', 'K', 'S', 'M', or 'X'\n\n";
		}
		std::cout << "\n\n\n\n";
	}
	while(continueBrowsing);
}
