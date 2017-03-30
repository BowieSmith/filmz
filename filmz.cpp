#include "Film.h"
#include "FilmDatabase.h"
#include "Menu.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

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
	db.displaySearch("studio","uni");

	std::cout << "\nCall displaySearch() with queryString \"12\":\n\n";
	db.displaySearch("month","12");

	std::string queryString = "er";
	std::cout << "\nCall displaySearch() with queryString: \"" << queryString << "\"\n\n";
	db.displaySearch("keywords",queryString);
}

int main()
{
	FilmDatabase filmDatabase2016("Films2016.csv");
	Menu interface(filmDatabase2016);

	interface.mainMenu();


//	testDatabase(filmDatabase2016);

	return 0;
}
