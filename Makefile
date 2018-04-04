CPPFLAGS = -O0 -Wall -pedantic
OBJECTS = main.o jogador.o jogo.o

prog: $(OBJECTS)
	g++ $(CPPFLAGS) -o prog $(OBJECTS)

prog_debug: $(OBJECTS)
	g++ $(CPPFLAGS) -g -o prog_debug $(OBJECTS)

main.o:
	g++ $(CPPFLAGS) -c main.cpp

jogador.o:
	g++ $(CPPFLAGS) -c jogador.cpp

jogo.o:
	g++ $(CPPFLAGS) -c jogo.cpp

clean:
	rm -f core prog $(OBJECTS)
