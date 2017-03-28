/**
 * @file FileDatabase.cpp
 * @author Bowie Smith
 * @date March 2017
 */

#include "FilmDatabase.h"
#include "Film.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

void displayFilmDataHeader()
{
	std::cout << std::right << std::setw(68) << "Total"
			  << std::setw(14) << "Total"
			  << std::setw(11) << "Opening"
			  << std::setw(14) << "Opening"
			  << std::setw(10) << "Opening\n";

	std::cout << std::left  << std::setw(5) << "Rank"
			  << std::setw(50) << "Title"
			  << std::setw(8) << "Studio"
			  << std::setw(14) << "Gross"
			  << std::setw(9) << "Theaters"
			  << std::setw(14) << "Gross"
			  << std::setw(9) << "Theaters"
			  << std::setw(8) << "Date\n"
			  << std::endl;
}

int openingDateToMonthNumber(std::string openingDate)
{
	std::string month = openingDate.substr(openingDate.size() - 3, std::string::npos);
	int monthInt;

	if (month == "Jan")
		monthInt = 1;
	else if (month == "Feb")
		monthInt = 2;
	else if (month == "Mar")
		monthInt = 3;
	else if (month == "Apr")
		monthInt = 4;
	else if (month == "May")
		monthInt = 5;
	else if (month == "Jun")
		monthInt = 6;
	else if (month == "Jul")
		monthInt = 7;
	else if (month == "Aug")
		monthInt = 8;
	else if (month == "Sep")
		monthInt = 9;
	else if (month == "Oct")
		monthInt = 10;
	else if (month == "Nov")
		monthInt = 11;
	else if (month == "Dec")
		monthInt = 12;

	return monthInt;
}

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

void displayFilmForMatchingStudio(Film& aFilm)
{
	std::string thisStudioLowercase = aFilm.getStudio();
	std::transform(thisStudioLowercase.begin(), thisStudioLowercase.end(), thisStudioLowercase.begin(), ::tolower);
	if (thisStudioLowercase == Film::studioSearchValue)
	{
		Film::studioSearchSuccess = true;
		aFilm.displayFilmData();
	}
}

void displayFilmForMatchingMonth(Film& aFilm)
{
	int thisFilmOpeningDateMonth = openingDateToMonthNumber(aFilm.getOpeningDate());
	if (thisFilmOpeningDateMonth == Film::monthSearchValue)
	{
		Film::monthSearchSuccess = true;
		aFilm.displayFilmData();
	}
}

void displayFilmsWithMatchingKeywords(Film& aFilm)
{
	std::string thisTitleLowercase = aFilm.getTitle();
	std::transform(thisTitleLowercase.begin(), thisTitleLowercase.end(), thisTitleLowercase.begin(), ::tolower);

	int count = 0;
	bool match = false;

	while (!match && (count < Film::keywordSearchVector.size()))
	{
		if (thisTitleLowercase.find(Film::keywordSearchVector[count]) != std::string::npos)
		{
			match = true;
			aFilm.displayFilmData();
			Film::keywordSearchSuccess = true;
		}
		count++;
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
		std::cout << "No title matching the search string \"" << originalSearch
		   		  << "\" was found." << "\n\n";	
	}
	Film::titleSearchSuccess = false;
}

void FilmDatabase::searchStudio(std::string studio)
{
	std::string originalSearch = studio;
	std::transform(studio.begin(), studio.end(), studio.begin(), ::tolower);
	Film::studioSearchValue = studio;
	filmDatabaseBST.inorderTraverse(displayFilmForMatchingStudio);

	if (!Film::studioSearchSuccess)
	{
		std::cout << "No studio matching the search string \"" << originalSearch
				  <<"\" was found." << "\n\n";
	}
	Film::studioSearchSuccess = false;
}

void FilmDatabase::searchMonth(std::string month) throw(PrecondViolatedExcep)
{
	std::string originalSearch = month;
	int monthInt = std::stoi(month);

	if (monthInt < 1 || monthInt > 12)
		throw PrecondViolatedExcep("Month value must be between 1 and 12.");

	Film::monthSearchValue = monthInt;
	filmDatabaseBST.inorderTraverse(displayFilmForMatchingMonth);

	if (!Film::monthSearchSuccess)
	{
		std::cout << "No film released in the month matching \"" << originalSearch
				  <<"\" was found." << "\n\n";
	}
	Film::monthSearchSuccess = false;
}

void FilmDatabase::searchKeywords(std::string keywords)
{
	std::string originalSearch = keywords;
	std::transform(keywords.begin(), keywords.end(), keywords.begin(), ::tolower);

	std::istringstream ss(keywords);
	std::string currentKeyword;

	Film::keywordSearchVector.clear();

	while (std::getline(ss, currentKeyword, ','))
	{
		Film::keywordSearchVector.push_back(currentKeyword);
	}

	filmDatabaseBST.inorderTraverse(displayFilmsWithMatchingKeywords);

	if (!Film::keywordSearchSuccess)
	{
		std::cout << "No films with a title matching the keywords \"" << originalSearch
				  <<"\" were found." << "\n\n";
	}
	Film::keywordSearchSuccess = false;
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
	displayFilmDataHeader();

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
								 const std::string queryString) throw(PrecondViolatedExcep)
{
	displayFilmDataHeader();

	if (searchType == "title")
	{
		searchTitle(queryString);
	}
	else if (searchType == "keywords")
	{
		searchKeywords(queryString);
	}
	else if (searchType == "studio")
	{
		searchStudio(queryString);
	}
	else if (searchType == "month")
	{
		searchMonth(queryString);
	}
	else
	{
		std::string errorMessage = "displayReport(std::string) must be passed an";
		errorMessage += "\nargument equal to \"title\",\"keywords\",\"studio\", or \"month\"";
		throw PrecondViolatedExcep(errorMessage);
	}
}
