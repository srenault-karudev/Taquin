/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "menu.h"

int main (void){
  InitialiserGraphique();
  CreerFenetre(350,100,900,650);
  while(1){
    menu();
  }
  return EXIT_SUCCESS;
}
