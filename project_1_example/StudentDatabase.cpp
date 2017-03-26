/**
 * @file StudentDatabase.cpp
 * @author Professor Gregory
 * Implementation of the StudentDatabase class
 */
#include "StudentDatabase.h"
#include <iostream>
#include <fstream>

using namespace std;

/*
 * Saves the contents of a tree node (a student) to the text file
 */
void saveData(Student& anItem)
{
   anItem.saveData(); 
   anItem.printStudent();
}


/*
 * Displays the contents of a tree node (a student)
 */
void display(Student& anItem)
{
   anItem.printStudent();
}

/*
 * Displays the student with a specified id */
void findStudent(Student& anItem)
{
   if (anItem.getId() == Student::searchId)
	   anItem.printStudent();
}

void StudentDatabase::add(const Student& aStudent)
{  studentDatabaseBST.add(aStudent);
}

bool StudentDatabase::remove(const Student& aStudent)
{  return studentDatabaseBST.remove(aStudent);
}

void StudentDatabase::search(int id)
{  Student::searchId = id;
   
	cout << "Student record with id of " << id << ": " << endl;
   studentDatabaseBST.inorderTraverse(findStudent);
 }

void StudentDatabase::displayData (void)
{
   cout << endl << "Inorder traversal" << endl;
   studentDatabaseBST.inorderTraverse(display);
   cout << endl << "Preorder traversal" << endl;
   studentDatabaseBST.preorderTraverse(display);
   cout << endl << "Postorder traversal" << endl;
   studentDatabaseBST.postorderTraverse(display);
}


void StudentDatabase::saveDatabase (void)
{
   // output the data to a text file
   cout << endl << "Saving all data in the binary search tree to a file named " 
        << OUTPUT_FILENAME << "." << endl;
   studentDatabaseBST.preorderTraverse(saveData);
   Student::closeOutputFile();
}




