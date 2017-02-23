all:
	g++ main.cpp tile.cpp tile.h player.cpp player.h finish.cpp finish.h path.cpp path.h -lSDL2 -std=c++11 -o main
