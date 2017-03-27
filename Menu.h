/**
 * @file Menu.h
 * @author Bowie Smith
 * @date March 2017
 *
 * This class provides a menu-driven user interface to the FilmDatabase class.
 * The primary options the menu provides are:
 * 		About the Application - To describe what the application is and how
 * 			it works
 * 		Reports - To display reports on movie rank and alphabetical ordering
 * 			per the movies uploaded to the database from file
 * 		Search the Database - To search for movies by Title, Keywords,
 * 			producing Studio, and Month of release
 */

#ifndef MENU_
#define MENU_

#include "FilmDatabase.h"

class Menu
{
private:
	// Database this menu interfaces to
	FilmDatabase db;

	/**
	 * This function displays information about what the application is and
	 * how it works.
	 */
	void aboutApplication();

	/**
	 * This function launches a sub-menu to give the user various options for
	 * creating reports on the movies stored in the database.
	 */
	void reportMenu();

	/**
	 * This function launches a sub-menu to give the user various options for
	 * searching the database.
	 */
	void searchMenu();

public:
	/**
	 * Menu constructor.
	 * Loads FilmDatabase in to Menu class.
	 * @param filmDB - FilmDatabase reference
	 */
	Menu(FilmDatabase& filmDB);

	/**
	 * This starts the main menu and gives options to the user to search the
	 * database, display reports, or give information about the application.
	 */
	void mainMenu();
};

#endif
