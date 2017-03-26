/**
 * @file Film.h
 * @author Bowie Smith
 * @date March 2017
 *
 * The Film class stores the following statistics for a film:
 * Rank(by Total Gross), Title, Studio, Total Gross, Total Theaters,
 * Opening Gross, Opening Theaters, Opening Date.
 * Film objects will be used by the FilmDatabase class to store
 * films in the nodes of a Binary Search Tree.
 */

#ifndef FILM_H_
#define FILM_H_

#include <string>

class Film
{
private:
	// Film rank in terms of gross (2016)
	int rank;

	// Film title
	std::string title;

	// Studio which produced film
	std::string studio;

	// Total gross
	double totalGross;

	// Total number of theaters showing film
	int totalTheaters;

	// Gross opening weekend
	double openingGross;

	// Total number of theaters showing film opening weekend
	int openingTheaters;

	// Film opening date
	std::string openingDate;

public:
	// Public variable to search by rankNumber
	static int rankSearchValue;

	// Public variable to search by title
	static std::string titleSearchValue;
	// Public variable to flag if title search is successful
	static bool titleSearchSuccess;

	// Public variable to search by studio
	static std::string studioSearchValue;
	// Public variable to flag if studio search is successful
	static bool studioSearchSuccess;

	/**
	 * Default Film Constructor
	 */
	Film();

	/**
	 * Overloaded Film constructor
	 * @param rank - Film rank
	 * @param title - Film Title
	 * @param studio - Studio which produced film
	 * @param totalGross - Total gross income ($)
	 * @param totalTheaters - Total theaters showing film
	 * @param openingGross - Gross income from opening weekend ($)
	 * @param openingTheaters - Total theaters showing film opening weekend
	 * @param openingDate - Film opening date
	 */
	Film(int rank, std::string title, std::string studio, double totalGross,
		 int totalTheaters, double openingGross, int openingTheaters,
		 std::string openingDate);

	/**
	 * Overloaded Film constructor.
	 * This constructor receives a line of comma separated values in the order:
	 * Rank, Title, Studio, TotalGross, TotalTheaters, OpeningGross,
	 * OpenTheaters, OpeningDate.
	 * @param inputLine - String input line of film statistics
	 */
	Film(const std::string inputLine);

	/**
	 * Return film rank
	 * @return - Film ranking (1-100)
	 */
	int getRank();

	/**
	 * Return film title
	 * @return - Title of film
	 */
	std::string getTitle();

	/**
	 * Return film studio
	 * @return - Name of studio which produced film
	 */
	std::string getStudio();

	/**
	 * Display film data in readable format
	 */
	void displayFilmData();

	/**
	 * Defines less than operator "<" for Film objects.
	 * @param rightOperand - right operand of type film.
	 * @return True if the title of the calling object is less than
	 * 		   the title of the argument object.
	 */
	bool operator<(const Film& rightOperand);

	/**
	 * Defines greater than operator ">" for Film objects.
	 * @param leftOperand - left operand of type film.
	 * @return True if the title of the calling object is greater
	 * 		   than the title of the argument object.
	 */
	bool operator>(const Film& rightOperand);

	/**
	 * Defines equality operator "==" for Film objects.
	 * @param rightOperand - right operand of type film.
	 * @return True if calling object has the same title as the argument object.
	 */
	bool operator==(const Film& rightOperand);
};

#endif
