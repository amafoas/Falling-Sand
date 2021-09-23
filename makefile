CC = g++

NAME = main

FLAGS = -w
LIBS = -lSDL2

OBJS = build/main.o build/Game.o build/Window.o build/Particle.o

all : $(OBJS)
	$(CC) $(OBJS) $(FLAGS) $(LIBS) -o $(NAME)

build/main.o: source/main.cpp
	$(CC) -c source/main.cpp -o build/main.o

build/Game.o: source/Game.cpp include/Game.hpp
	$(CC) -c source/Game.cpp -o build/Game.o

build/Window.o: source/Window.cpp include/Window.hpp
	$(CC) -c source/Window.cpp -o build/Window.o

build/Particle.o: source/Particle.cpp include/Particle.hpp
	$(CC) -c source/Particle.cpp -o build/Particle.o

clean:
	rm build/*