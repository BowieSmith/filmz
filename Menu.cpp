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
	std::cout << "\n\n\tGREETINGS!\n"
			  << "\n\tWelcome to filmz!  Your one-stop shop for movie title browsing!"
			  << "\n\tfilmz stores film titles along with the following information:"
			  << "\n\t\t-Film Rank (by total gross)"
			  << "\n\t\t-Film Title"
			  << "\n\t\t-Producing Studio"
			  << "\n\t\t-Total Gross"
			  << "\n\t\t-Total theaters which Showed the Film"
			  << "\n\t\t-Opening Weekend Gross"
			  << "\n\t\t-Total Theaters which Showed the Film Opening Weekend"
			  << "\n\t\t-Opening Data"
			  << "\n\n\tfilmz allows you to generate reports of all movies based on rank"
			  << "\n\tand alphabetical ordering by title."
			  << "\n\n\tfilmz also gives you the ability to search for films by:"
			  << "\n\tProducing Studio, Month of Release, or Title Name (full name or keywords)"
			  << "\n\n\tUnfortunately, filmz currently only has titles from 2016, but more are"
			  << "\n\tplanned to come!"
			  << "\n\n\tFor the tech savvy folks out there, you may be wondering how this"
			  << "\n\tapplication works? First, film data is read into the computer through"
			  << "\n\ta file with comma-separated values. (This is a simple format with--you"
			  << "\n\tguessed it--a list of comma-separated values!) Each line in the file of"
			  << "\n\tcomma separated values stores the information for one movie. The information"
			  << "\n\tfor each movie is then separated into exclusive chunks of movie data. In"
			  << "\n\tcomputer jargon, these chunks of movie data are called 'objects'. The"
			  << "\n\tobjects are stored in a tree structure (called a binary search tree) which"
			  << "\n\tmakes searching for movies by title extremely fast! The tree of films"
			  << "\n\tis a type of database--a place to store data with optimised data structures"
			  << "\n\tfor making search and other operations fast. The Menu you see is simply"
			  << "\n\tan interface for interacting with database."
			  << "\n\n\tHappy browsing!\n"

			  << "\n\tPress ENTER to continue...\n\n";

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
