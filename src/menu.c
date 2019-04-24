/* Auteur : Pierre villiers et Steven Renault*/

#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include "menu.h"
#include "parametre.h"



/* choix du menu avec les touches directionnelles du clavier  */
int MenuClavier(int etat){
  couleur r;
  couleur b;
  int t;

  r=CouleurParNom("red");

  b=CouleurParNom("black");
  ChoisirCouleurDessin(b);
  DessinerRectangle(186,262,220,93);
  DessinerRectangle(177,437,245,103);
  
 
  if(ToucheEnAttente()){
    t=Touche();
  }
  if(t==XK_Down){
    DessinerRectangle(186,262,220,93);
    ChoisirCouleurDessin(r);
    etat=2;
    DessinerRectangle(177,437,245,103);
    ChoisirCouleurDessin(b);   
  }
    
  else if(t==XK_Up){
    DessinerRectangle(177,437,245,103);       
    ChoisirCouleurDessin(r);
    etat=1;    
    DessinerRectangle(186,262,220,93);
    ChoisirCouleurDessin(b);   
  }

  else if(t==XK_Return){
    if(etat==1){
      etat=3;
    }
    else if(etat==2){
      FermerGraphique();
      exit(2);
    }
    else if(etat==0){
      printf("Vous n'avez rien choisi  %d\n",etat);
     
    }
  }
  return etat;

}

/* Menu du jeu*/

void menu(void){
  int a=0;
  int etat=0;
 
      
  ChargerImageFond("../images/menu_taquin.png");
  while(a==0){
    
    while(!SourisCliquee()){
      etat=MenuClavier(etat);
      if(etat==3){
	EffacerEcran(CouleurParNom("white"));
	ChargerImageFond("../images/choix image.png");
	SelectImage();
	return;
      }
    }
  
    SourisPosition();   
  
    if(_X>=190 && _X<=420 && _Y>=265 && _Y<=375){
   
      EffacerEcran(CouleurParNom("white"));  
      ChargerImageFond("../images/choix image.png");
      SelectImage();
      a = 1;
    }
    if(_X>=185 && _X<=435 && _Y>=445 && _Y<=555){
     
      FermerGraphique();
      exit(1);
    
    }
  
     
  }
  return;
  
}


