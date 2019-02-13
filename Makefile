nome = tp2ex1

all:
	g++ -o $(nome) src/main.cpp src/Cardapio.h src/TLista.h src/TLista.cpp

clean:
	-rm -f *.o *~

run:
	./$(nome)
