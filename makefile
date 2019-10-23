DungeonCrawler: run

run: Item.o Entity.o Effect.o Classlib.o Functions.o GameData.o Ability.o Main.o Room.o
	g++ Item.o Entity.o Effect.o Classlib.o Functions.o GameData.o Ability.o Main.o Room.o -o run

Item.o: Main-Item.cpp Item.cpp Item.h
	g++ -c  Item.cpp -o Item.o

Entity.o: NPCGenerator.cpp Entity.cpp Entity.h
	g++ -c Entity.cpp -o Entity.o

Effect.o: Effect.cpp Effect.h
	g++ -c Effect.cpp -o Effect.o

Classlib.o: classlib.cpp Classlib.h
	g++ -c classlib.cpp -o Classlib.o

Functions.o: functions.cpp Functions.h
	g++ -c functions.cpp -o Functions.o

GameData.o: GameData.cpp GameData.h
	g++ -c GameData.cpp -o GameData.o

Ability.o: Main-Ability.cpp Ability.cpp Ability.h
	g++ -c Ability.cpp -o Ability.o

Main.o: Main.cpp
	g++ -c Main.cpp -o Main.o

Room.o: Room.cpp Room.h
	g++ -c Room.cpp -o Room.o

clean:
	rm -f *.o run