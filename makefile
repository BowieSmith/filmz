# Makefile for FilmDatabase Application.

objects = Film.o FilmDatabase.o Menu.o NotFoundException.o PrecondViolatedExcep.o filmDatabaseApp.o

filmDatabaseApp: $(objects)
	g++ -std=gnu++11 -o filmDatabaseApp $(objects)
Film.o: Film.cpp Film.h 
	g++ -std=gnu++11 -ggdb -c Film.cpp
FilmDatabase.o: FilmDatabase.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c FilmDatabase.cpp
Menu.o: Menu.cpp Menu.h FilmDatabase.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h
	g++ -std=gnu++11 -ggdb -c Menu.cpp
NotFoundException.o: NotFoundException.cpp NotFoundException.h 
	g++ -std=gnu++11 -ggdb -c NotFoundException.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h 
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp
filmDatabaseApp.o: filmDatabaseApp.cpp FilmDatabase.h BinarySearchTree.h BinaryTreeInterface.h BinaryNodeTree.h BinaryNode.h NotFoundException.h PrecondViolatedExcep.h Film.h Menu.h
	g++ -std=gnu++11 -ggdb -c filmDatabaseApp.cpp 
