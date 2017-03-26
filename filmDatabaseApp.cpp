#include "Film.h"
#include "FilmDatabase.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>

int main()
{
	FilmDatabase filmDatabase2016("Films2016.csv");

	std::cout << "\nFilms in alphabetical order:\n\n";
	filmDatabase2016.displayReport("title");

	std::cout << "\nFilms in order of rank by total gross:\n\n";
	filmDatabase2016.displayReport("rank");

	std::cout << "\nCall displaySearch() with queryString \"MoA\":\n\n";
	filmDatabase2016.displaySearch("title","MoA");

	std::cout << "\nCall displaySearch() with queryString \"MoAnA\":\n\n";
	filmDatabase2016.displaySearch("title","MoAnA");

	std::cout << "\nCall displaySearch() with queryString \"Sony\":\n\n";
	filmDatabase2016.displaySearch("studio","uni");

	return 0;
}
