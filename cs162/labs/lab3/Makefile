CC = g++ -std=c++11
exe_file = lab_3
$(exe_file): card.o deck.o driver.o
	$(CC) card.o deck.o driver.o -o $(exe_file)
cards.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp