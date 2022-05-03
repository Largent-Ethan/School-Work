CC = g++ -std=c++11
exe_file = library_organizer_imp
$(exe_file): library_organizer_imp.o library_organizer.o
	$(CC) library_organizer_imp.o library_organizer.o -o $(exe_file)
library_organizer_imp.o: library_organizer_imp.cpp
	$(CC) -c library_organizer_imp.cpp
library_organizer.o: library_organizer.cpp
	$(CC) -c library_organizer.cpp