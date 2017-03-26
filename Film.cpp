/**
 * @file Film.cpp
 * @author Bowie Smith
 * @date March 2017
 */

#include "Film.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>

int Film::rankSearchValue = 0;

std::string Film::titleSearchValue = "";
bool Film::titleSearchSuccess = false;

std::string Film::studioSearchValue = "";
bool Film::studioSearchSuccess = false;

/**
 * Returns double value as formatted string in form "$x,xxx,xxx"
 * @param value - double value to be formatted
 * @return formatted string
 */
std::string doubleToDollar(double value)
{
	// Cast double to int to effectively truncate any zeros after radix
	int intRepresentation = static_cast<int>(value);

	// Converted integer representation of value to string
	std::string unformattedString = std::to_string(intRepresentation);

	std::string formattedString;
	int count = 0;
	std::stack<std::string> formatStack;
	std::string currentCharacter;
	
	// Traverse unformattedString from the end, pushing each character onto the
	// formatStack.  Every three characters, add a "," to the stack to format
	// as currency.
	for (int i = unformattedString.size() - 1; i >= 0; i--)
	{
		currentCharacter = unformattedString[i];
		formatStack.push(currentCharacter);
		count++;
		if (count % 3 == 0 && i != 0)
			formatStack.push(",");
	}

	// Append "$" character to formattedString.  Pop characters off formatStack
	// and append to formattedString.	
	formattedString += "$";
	while (!formatStack.empty())
	{
		formattedString += formatStack.top();
		formatStack.pop();
	}

	return formattedString;
}

Film::Film()
{
}

Film::Film(int rank, std::string title, std::string studio, double totalGross,
		   int totalTheaters, double openingGross, int openingTheaters,
		   std::string openingDate)
	: rank(rank), title(title), studio(studio), totalGross(totalGross),
	  totalTheaters(totalTheaters), openingGross(openingGross),
	  openingTheaters(openingTheaters), openingDate(openingDate)
{
}

Film::Film(const std::string inputLine)
{
	std::istringstream ss(inputLine);
	std::string token;
	std::vector<std::string> tokenVector;

	while (std::getline(ss, token, ','))
	{
		tokenVector.push_back(token);
	}

	rank = std::stoi(tokenVector[0]);
	title = tokenVector[1];
	studio = tokenVector[2];
	totalGross = std::stod(tokenVector[3]);
	totalTheaters = std::stoi(tokenVector[4]);
	openingGross = std::stod(tokenVector[5]);
	openingTheaters = std::stoi(tokenVector[6]);
	openingDate = tokenVector[7];
}

int Film::getRank()
{
	return rank;
}

std::string Film::getTitle()
{
	return title;
}

std::string Film::getStudio()
{
	return studio;
}

void Film::displayFilmData()
{
	std::cout << std::left << std::fixed << std::setw(4) << rank
			  << std::setw(50) << title
			  << std::setw(8) << studio
			  << std::setw(14) << doubleToDollar(totalGross)
			  << std::setw(6) << totalTheaters
			  << std::setw(14) << doubleToDollar(openingGross)
			  << std::setw(6) << openingTheaters
			  << std::setw(8) << openingDate << std::endl;
}

bool Film::operator<(const Film& rightOperand)
{
	return title < rightOperand.title;
}

bool Film::operator>(const Film& rightOperand)
{
	return title > rightOperand.title;
}

bool Film::operator==(const Film& rightOperand)
{
	return title == rightOperand.title;
}
