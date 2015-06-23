all: mahjong

#COMPILER=clang -stdlib=libc++

COMPILER=g++

OBJECTS = Tile.o Hand.o Player.o AIPlayer.o Table.o 

mahjong: $(OBJECTS) mahjong.cpp
	$(COMPILER) -std=c++11 $(OBJECTS) mahjong.cpp -o mahjong

Table.o: Table.cpp Table.h
	$(COMPILER) -std=c++11 -c Table.cpp

Tile.o: Tile.cpp Tile.h
	$(COMPILER) -std=c++11 -c Tile.cpp

Hand.o: Hand.cpp Hand.h
	$(COMPILER) -std=c++11 -c Hand.cpp

Player.o: Player.cpp Player.h
	$(COMPILER) -std=c++11 -c Player.cpp

AIPlayer.o: AIPlayer.cpp AIPlayer.h
	$(COMPILER) -std=c++11 -c AIPlayer.cpp
