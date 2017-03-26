# Makefile for FilmDatabase Application.

filmDatabaseApp: Film.o FilmDatabase.o NotFoundException.o PrecondViolatedExcep.o filmDatabaseApp.o 
	g++ -std=gnu++11 -o filmDatabaseApp Film.o FilmDatabase.o NotFoundException.o PrecondViolatedExcep.o filmDatabaseApp.o
Film.o: Film.cpp Film.h 
	g++ -std=gnu++11 -ggdb -c Film.cpp
FilmDatabase.o: FilmDatabase.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c FilmDatabase.cpp
NotFoundException.o: NotFoundException.cpp NotFoundException.h 
	g++ -std=gnu++11 -ggdb -c NotFoundException.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
filmDatabaseApp.o: filmDatabaseApp.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c filmDatabaseApp.cpp 
