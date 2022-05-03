CC = g++ -std=c++11
exe_file = assignment_2
$(exe_file): card.o deck.o hand.o player.o game.o driver.o
	$(CC) card.o deck.o hand.o player.o game.o driver.o -o $(exe_file)
cards.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp