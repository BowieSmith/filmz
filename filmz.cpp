/**
 * @file filmz.cpp
 * @author Bowie Smith
 * @date March 2017
 *
 * This file contains the main() function to drive the filmz application.
 * filmz is a movie browsing application. It loads a list of movie statistics
 * into a database, which is built using a binary search tree. The database
 * is interfaced through a Menu, which holds a reference to the database
 * and calls the database's public methods based on user input.
 */

#include "Film.h"
#include "FilmDatabase.h"
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

/**
 * Test function to test FilmDatabase methods.
 * @para FilmDatabase
 */
void testDatabase(FilmDatabase& db)
{
	std::cout << "\nFilms in alphabetical order:\n\n";
	db.displayReport("title");

	std::cout << "\nFilms in order of rank by total gross:\n\n";
	db.displayReport("rank");

	std::cout << "\nCall displaySearch() with queryString \"MoA\":\n\n";
	db.displaySearch("title","MoA");

	std::cout << "\nCall displaySearch() with queryString \"MoAnA\":\n\n";
	db.displaySearch("title","MoAnA");

	std::cout << "\nCall displaySearch() with queryString \"Sony\":\n\n";
	db.displaySearch("studio","sony");

	std::cout << "\nCall displaySearch() with queryString \"12\":\n\n";
	db.displaySearch("month","12");

	std::string queryString = "er";
	std::cout << "\nCall displaySearch() with queryString: \"" << queryString << "\"\n\n";
	db.displaySearch("keywords",queryString);
}

/**
 * main() is the driving method.
 * The FilmDatabase(std::string) constructor is called to build the database
 * with the list of comma-separated values found in the filename passed as a
 * parameter.
 * The Menu(FilmDatabase) constructor is called to pass the newly created
 * database to the menu called "interface".
 * The interface is launched when the menu calls the method mainMenu().
 */
int main()
{
	FilmDatabase filmDatabase2016("Films2016.csv");
	Menu interface(filmDatabase2016);

	interface.mainMenu();

//	testDatabase(filmDatabase2016);

	return 0;
}
