/**
 * @file BSTTest.cpp
 * @author Professor Gregory
 * This program demonstrates the use of a BinarySearchTree to store
 * items of the Student class type. It creates some Student objects, 
 * adds them to a binary search tree, inputs data for a Student object
 * and adds that student to the tree. It removes a Student object from
 * the tree. Next, it displays the data stored in the tree using all 
 * three types of tree traversals, and then saves the data to a text 
 * file using a preorder traversal.
 */
#include "StudentDatabase.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void explanation(void);


int main (void)
{
   explanation();
    
   StudentDatabase studentDB; // database to store Student objects
	 
	Student item1("Martin", "410-555-2222");  // first student to add
   Student item2("Edwards", "410-555-1222"); // second student to add
   Student item3("Baker", "410-555-2122");   // third student to add
   Student item4("George", "410-555-2212");  // fourth student to add
   Student item5("Rogers", "410-555-2221");  // fifth student to add
   Student item6("Phillips", "410-555-1122");// sixth student to add
   Student item7("Turner", "410-555-2112");  // seventh student to add
   Student item8("Smith", "410-555-2211");   // eighth student to add
   cout << "Adding " << item1.getName() << " to binary search tree." << endl;
   studentDB.add (item1);
   cout << "Adding " << item2.getName() << " to binary search tree." << endl;
   studentDB.add (item2);
   cout << "Adding " << item3.getName() << " to binary search tree." << endl;
   studentDB.add (item3);
   cout << "Adding " << item4.getName() << " to binary search tree." << endl;
   studentDB.add (item4);
   cout << "Adding " << item5.getName() << " to binary search tree." << endl;
   studentDB.add (item5);
   cout << "Adding " << item6.getName() << " to binary search tree." << endl;
   studentDB.add (item6);
   cout << "Adding " << item7.getName() << " to binary search tree." << endl;
   studentDB.add (item7);
   cout << "Adding " << item8.getName() << " to binary search tree." << endl << endl;
   studentDB.add (item8);
   
   Student item9;  // student object to input from user
   cout << "Next person added to binary search tree will be entered by the user."
        << endl;
   item9.inputStudent(); // input a ninth student to add
   cout << "Adding " << item9.getName() << " to binary search tree." << endl << endl;
   studentDB.add (item9);
   
   // find and display George
	cout << "Searching for George by id of 103" << endl;
	studentDB.search(103);
	
	// Remove George
   Student george ("George", " "); // Student object required as argument
   cout << endl << "Remove George" << endl;
   bool success = studentDB.remove(george);
   if (success)
      cout << george.getName() << " was successfully deleted from the"
              << " binary search tree." << endl;
      else
         cout << george.getName() << " was NOT successfully deleted from"
              << " the binary search tree." << endl;

    studentDB.displayData();
    studentDB.saveDatabase();

    return EXIT_SUCCESS;
}


/**
 * Provides an explanation of the program for the user
 */
void explanation(void)
{
    cout << "This program demonstrates the use of a binary search tree" << endl;
    cout << "to store items of the Student class type to help CTP 250" << endl;
    cout << "students understand how to use the binary search tree classes" << endl;
    cout << "provided by the textbook. The program creates eight arbitrary" << endl;
    cout << "pre-defined Student objects, which consist of name, id," << endl;
    cout << "and phone, and adds them to a binary search tree. It then" << endl;
    cout << "inputs data for a new Student object from the user, giving" << endl;
    cout << "the user specific instructions about data entry. The program" << endl;
    cout << "adds the entered Student object to the binary search tree." << endl << endl;
    cout << "The program searches for a specific student in the tree, and" << endl;
    cout << "deletes that student. The program then displays the" << endl;
    cout << "data in the binary search tree using an inorder traversal," << endl;
    cout << "which results in an alphabetical listing of Student objects" << endl;
    cout << "in the tree. Next, the program displays the contents of the" << endl;
    cout << "tree using a preorder and a postorder traversal, so the order" << endl;
    cout << "of the Student objects appears random. Before exiting, the"<< endl;
    cout << "program saves the data for each Student object in the tree" << endl;
    cout << "to a text file using a preorder traversal." << endl  << endl;
}

