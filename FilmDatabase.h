/**
 * @file FilmDatabase.h
 * @author Bowie Smith
 * @date March 2017
 *
 * This class creates a database to hold films in a binary search tree.
 * The Film class is used to store the film objects, which are stored in
 * the nodes of the tree.
 */

#ifndef FILM_DATABASE_
#define FILM_DATABASE_

#include "BinarySearchTree.h"
#include "Film.h"

class FilmDatabase
{
private:
	// Binary search tree to hold films
	BinarySearchTree<Film> filmDatabaseBST;

	/**
	 * Helper method to displayReport()
	 * When "rank" is passed to displayReport(), searchRank() is called.
	 * This method sets the public static variable Film::rankSearchValue to the
	 * value passed as an argument and displays the film record if a match
	 * is found.
	 * @param rank - Rank value to search for
	 */
	void searchRank(int rank);

	/**
	 * Helper method to displaySearch()
	 * When "title" is passed to displaySearch(), searchTitle() is called.
	 * This method sets the public static variable Film::titleSearchValue to the
	 * value passed as an argument and displays the film record if a match
	 * is found.
	 * @param title - Title value to search for
	 */
	void searchTitle(std::string title);

	/**
	 * Helper method to displaySearch()
	 * When "studio" is passed to displaySearch(), searchStudio() is called.
	 * This method sets the public static variable Film::studioSearchValue to
	 * the value passed as an argument and displays all films produced by the
	 * corresponding studio.
	 * @param studio - Studio value to search for
	 */
	void searchStudio(std::string studio);

	/**
	 * Add Film object to database.
	 * @param film - Film object
	 */
	void add(const Film& aFilm);

public:
	/**
	 * FilmDatabase default constructor
	 */
	FilmDatabase();

	/**
	 * FilmDatabase overloaded constructor
	 * @param filename - Name of file to construct database
	 * 		Assumes data file uses comma separated files and has no errors
	 */
	FilmDatabase(const std::string filename);

	/**
	 * Display report of all film titles.
	 * Pass string "title" or "rank" to choose ordering.
	 * @param order - String describing order for report
	 */
	void displayReport(const std::string orderBy) throw(PrecondViolatedExcep);
	
	/**
	 * Display all films matching search results.
	 * Pass string "title", "keyword", "studio", or "month" to dispatch the
	 * correct search method.  Pass query information as second argument.
	 * All searches are case insensitive.
	 * @param searchType - string describing type of search
	 * @param query - string with specific query information
	 * 		"title" - Exact name of film title
	 * 		"keyword" - Comma separated string of key words
	 * 		"studio" - Ecxact name of studio
	 * 		"month" - Enter 1-12 to search for films released in
	 * 				  corresponding month
	 */
	void displaySearch(const std::string searchType, const std::string queryString);
};

#endif
