DungeonCrawler: run

run: Item.o Entity.o Classlib.o Functions.o GameData.o Ability.o Main.o Main-Item.o Main-Ability.o NPCGenerator.o Room.o
	g++ Item.o Entity.o Classlib.o Functions.o GameData.o Ability.o Main.o Main-Item.o Main-Ability.o NPCGenerator.o Room.o -o run

Item.o: Main-Item.cpp Item.cpp Item.h
	g++ -c  Item.cpp -o Item.o

Entity.o: NPCGenerator.cpp Entity.cpp Entity.h
	g++ -c Entity.cpp -o Entity.o

Classlib.o: Classlib.cpp Classlib.h
	g++ -c Classlib.cpp -o Classlib.o

Functions.o: Functions.cpp Functions.h
	g++ -c Functions.cpp -o Functions.o

GameData.o: GameData.cpp GameData.h
	g++ -c GameData.cpp -o GameData.o

Ability.o: Main-Ability.cpp Ability.cpp Ability.h
	g++ -c Ability.cpp -o Ability.o

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

Main-Item.o: Main-Item.cpp
	g++ -c Main-Item.cpp -o Main-Item.o

Main-Ability.o: Main-Ability.cpp
	g++ -c Main-Ability.cpp -o Main-Ability.o

NPCGenerator.o: NPCGenerator.cpp
	g++ -c NPCGenerator.cpp -o NPCGenerator.o

Room.o: Room.cpp Room.h
	g++ -c Room.cpp -o Room.o

clean:
	rm -f *.o run