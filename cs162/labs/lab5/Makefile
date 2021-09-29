CC = g++ -std=c++11
exe_file = timed_coding_challenge
$(exe_file): date.o driver.o
	$(CC) date.o driver.o -o $(exe_file)
date.o: date.cpp
	$(CC) -c date.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp