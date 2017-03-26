# This is the makefile for the Student Database Example

objects = Student.o StudentDatabase.o NotFoundException.o PrecondViolatedExcep.o BSTTest.o

BSTTest.exe: $(objects)
	g++ -std=gnu++11 -o BSTTest.exe $(objects)
Student.o: Student.cpp Student.h 
	g++ -std=gnu++11 -ggdb -c Student.cpp
StudentDatabase.o: StudentDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Student.h
NotFoundException.o: NotFoundException.h 
PrecondViolatedExcep.o: PrecondViolatedExcep.h 
BSTTest.o: StudentDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Student.h
