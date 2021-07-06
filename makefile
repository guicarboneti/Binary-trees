# Leon e Guilherme

CFLAGS = -Wall -std=c99 # compilation flag

# object-file
objects = arvore_a.o arvore_b.o

all: busca

busca: busca.c $(objects)
	gcc busca.c -o busca $(objects) $(CFLAGS)
arvore_a.o: arvore_a.c arvore_a.h
	gcc -c arvore_a.c $(CFLAGS)
arvore_b.o: arvore_b.c arvore_b.h
	gcc -c arvore_b.c $(CFLAGS)
purge: clean
	-rm -f busca
clean:
	-rm -f $(objects)