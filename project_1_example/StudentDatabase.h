/**
 * @file StudentDatabase.h
 * @author Professor Gregory
 * @class StudentDatabase
 * This class creates a database using a BinarySearchTree to store
 * items of the Student class type. It creates some Student objects, 
 * adds them to a binary search tree, inputs data for a Student object
 * and adds that student to the tree. It searches for a Student object,
 * removing that Student object if it was found. Next, it displays the 
 * data using all three types of tree traversals, and then saves the 
 * data to a text file using a preorder traversal.
 */
#ifndef STUDENTDATABASE_H
#include "BinarySearchTree.h"
#include "Student.h"
using namespace std;

class StudentDatabase
{
private:
   /**
    * binary search tree to store Person data
    */
   BinarySearchTree<Student> studentDatabaseBST;

public:
   /**
    * Adds a Student object to the database.
	 * @param Student object to be added.
    */
   void add (const Student& aStudent);

   /**
    * Removes a Student object from the database.
	 * @param Student object to be removed.
	 * @return Whether the Student could successfully be removed from the database.
    */
   bool remove (const Student& aStudent);
	
	/**
    * Searches the database for a Student with a specified id.
	 * @param id of desired student.
    */
	void search(int id);
		
   /**
    * Displays the data in the database using inorder,
    * preorder, and postorder traversals.
    */
   void displayData (void);

   /**
    * Saves the database to an output file using a preorder
    * traversal.
    */
   void saveDatabase (void);
};

#define STUDENTDATABASE_H
#endif



