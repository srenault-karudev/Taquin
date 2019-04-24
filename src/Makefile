#Auteur : Pierre villiers et Steven Renault

#Taquin : Makefile

#CHAPITRE 1 : BUT FINAL

but : Taquin

#CHAPITRE 2 : VARIABLES

OFILES = menu.o \
	decoupage.o \
	generateur.o \
	jeu.o \
	mdj.o \
	parametre.o \
	plateau.o \
	victoire.o \
	main.o

CC = gcc

CFLAGS = -Wall -ansi -pedantic -g

#CHAPITRE 3 : DEPENDANCES

menu.o : menu.h parametre.h

decoupage.o :  decoupage.h 

generateur.o : generateur.h

jeu.o : jeu.h

mdj.o : mdj.h menu.h generateur.h plateau.h

parametre.o : parametre.h decoupage.h mdj.h

plateau.o : plateau.h victoire.h jeu.h decoupage.h menu.h

victoire.o : victoire.h menu.h

main.o : menu.h

#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES

Taquin : $(OFILES)
	$(CC) $(CFLAGS) -o Taquin $(OFILES) -lgraph

#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERE PAR LE MAKE           

clean :
	-rm -f $(OFILES) Taquin
        

#CHAPITRE 6 : BUT FACTICES	

.PHONY : but clean
