CC = g++

NAME = main

FLAGS = -w
LIBS = -lSDL2

OBJS = build/main.o build/Game.o build/Window.o build/ParticleSystem.o

all : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(LIBS) -o $(NAME)

build/main.o: source/main.cpp
	$(CC) -c source/main.cpp -o build/main.o

build/Game.o: source/Game.cpp include/Game.hpp
	$(CC) -c source/Game.cpp -o build/Game.o

build/ParticleSystem.o: source/ParticleSystem.cpp include/ParticleSystem.hpp
	$(CC) -c source/ParticleSystem.cpp -o build/ParticleSystem.o 

build/Window.o: source/Window.cpp include/Window.hpp
	$(CC) -c source/Window.cpp -o build/Window.o

clean:
	rm build/*