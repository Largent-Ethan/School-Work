CC = g++ -std=c++11
exe_file = lab_6
$(exe_file): square.o rectangle.o circle.o shape.o driver.o
	$(CC) square.o rectangle.o circle.o shape.o driver.o -o $(exe_file)
squares.o: square.cpp
	$(CC) -c square.cpp
rectangle.o: rectangle.cpp
	$(CC) -c rectangle.cpp
circle.o: circle.cpp
	$(CC) -c circle.cpp
shape.o: shape.cpp
	$(CC) -c shape.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp