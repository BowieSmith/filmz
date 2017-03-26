/**
 * @file Student.cpp
 * @author Professor Gregory
 * Implementation of the Student class
 */
#include "Student.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Define and initialize the static class members shared by all instances 
int Student::idNumbers = 100;                        // used to automatically generate idNum
ofstream Student::outFile(OUTPUT_FILENAME.c_str());  // open output file
int Student::searchId = 0;                    // used to search by id
                                         
Student::Student()
{  idNum = idNumbers++;         // auto initialize the idNum to the next available number
}


Student::Student(const string& newName,
       const string& newPhoneNumber)
       : name(newName), 
      phoneNumber(newPhoneNumber)
{  idNum = idNumbers++;         // auto initialize the idNum to the next available number
}


string Student::getName(void)
{
   return name;
}

int Student::getId(void)
{
   return idNum;
}

void Student::printStudent(void)
{
     cout << left << "Name: " << setw(10) << name << "  IdNum: " << setw(5) 
          << idNum << "  Phone: " << phoneNumber << endl;
}


void Student::inputStudent(void)
{
   string inputData;
   bool validInput = false;
   
   while (!validInput)
   {
      cout << "Enter last name for new person. Use uppercase for only the" << endl
           << "first letter:" << endl;
      getline(cin, inputData);
      if (isupper(inputData[0]))
      {
         name = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid name. Please try again." << endl;
   }
    
   validInput = false;
   while (!validInput)
   {
      cout << "Enter phone number for new student in the form ###-###-####:" << endl;
      getline(cin, inputData);
      if (inputData.length() == 12
          && isdigit(inputData[0]) && isdigit(inputData[1]) && isdigit(inputData[2])
          && inputData[3] == '-' && isdigit(inputData[4]) && isdigit(inputData[5])
          && isdigit(inputData[6]) && inputData[7] == '-' && isdigit(inputData[8])
          && isdigit(inputData[9]) && isdigit(inputData[10]) && isdigit(inputData[11]))
      {
         phoneNumber = inputData;
         validInput = true;
      }
      else
         cout << inputData << " is an invalid phone number. Please try again." << endl;
   }
}


void Student::saveData()
{
   if (outFile)
      outFile << name << "," << idNum << "," << phoneNumber << endl;
   else
       cout << "Error: Output file " << OUTPUT_FILENAME 
            << " is not ready for output." << endl << endl;
}


bool Student::operator> (const Student &right)
{
   return (name > right.name);
}



bool Student::operator< (const Student &right)
{
   return (name < right.name);
}


bool Student::operator== (const Student &right)
{
   return (name == right.name);
}

void Student::closeOutputFile()
{
   outFile.close();
}

