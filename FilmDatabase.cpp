/**
 * @file FileDatabase.cpp
 * @author Bowie Smith
 * @date March 2017
 */

#include "FilmDatabase.h"
#include "Film.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

void displayFilm(Film& aFilm)
{
	aFilm.displayFilmData();
}

void displayFilmForMatchingRank(Film& aFilm)
{
	if (aFilm.getRank() == Film::rankSearchValue)
	{
		aFilm.displayFilmData();
	}
}

void displayFilmForMatchingTitle(Film& aFilm)
{
	std::string thisTitleLowercase = aFilm.getTitle();
	std::transform(thisTitleLowercase.begin(), thisTitleLowercase.end(), thisTitleLowercase.begin(), ::tolower);
	if (thisTitleLowercase == Film::titleSearchValue)
	{
		Film::titleSearchSuccess = true;
		aFilm.displayFilmData();
	}
}

void FilmDatabase::searchRank(int rank)
{
	Film::rankSearchValue = rank;
	filmDatabaseBST.inorderTraverse(displayFilmForMatchingRank);
}

void FilmDatabase::searchTitle(std::string title)
{
	std::string originalSearch = title;
	std::transform(title.begin(), title.end(), title.begin(), ::tolower);
	Film::titleSearchValue = title;
	filmDatabaseBST.inorderTraverse(displayFilmForMatchingTitle);

	if (!Film::titleSearchSuccess)
	{
		std::cout << "No title match the search string \"" << originalSearch
		   		  << "\" was found." << "\n\n";	
	}
	Film::titleSearchSuccess = false;
}

void FilmDatabase::add(const Film& aFilm)
{
	filmDatabaseBST.add(aFilm);
}

FilmDatabase::FilmDatabase()
{
}

FilmDatabase::FilmDatabase(const std::string filename)
{
	std::ifstream inFile(filename);
	std::string line;
	Film tempFilm;

	while (inFile.peek() != EOF)
	{
		std::getline(inFile, line);
		tempFilm = Film(line);
		filmDatabaseBST.add(tempFilm);
	}
}

void FilmDatabase::displayReport(const std::string orderBy) throw(PrecondViolatedExcep)
{
	if (orderBy == "title")
	{
		filmDatabaseBST.inorderTraverse(displayFilm);
	}
	else if (orderBy == "rank")
	{
		for (int i = 1; i <= 100; i++)
		{
			searchRank(i);
		}
	}
	else
	{
		std::string errorMessage = "displayReport(std::string) must be passed an";
		errorMessage += "\nargument equal to \"title\" or \"rank\"";
		throw PrecondViolatedExcep(errorMessage);
	}
}

void FilmDatabase::displaySearch(const std::string searchType,
								 const std::string queryString)
{
	if (searchType == "title")
	{
		searchTitle(queryString);
	}
}
