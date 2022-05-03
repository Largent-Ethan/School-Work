CC = g++ -std=c++11
exe_file = zoo_tycoon
$(exe_file): black_bear.o tiger.o sea_lion.o animal.o zoo.o driver.o
	$(CC) black_bear.o tiger.o sea_lion.o animal.o zoo.o driver.o -o $(exe_file)
black_bears.o: black_bear.cpp
	$(CC) -c black_bear.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
sea_lion.o: sea_lion.cpp
	$(CC) -c sea_lion.cpp
animal.o: animal.cpp
	$(CC) -c animal.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp