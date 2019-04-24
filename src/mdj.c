/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include "menu.h"
#include "mdj.h"
#include "generateur.h"
#include "plateau.h"


/*fonction de chargement du fond*/
void fondImage(int x){
  if(x==1){
    ChargerImageFond("../images/decor_bulma.png"); 
  }
else if(x==2){
    ChargerImageFond("../images/decor_sangoku.png"); 
  }
  else if(x==3){
    ChargerImageFond("../images/decor_piccolo.png");
  }
}

/*Fonction qui affiche le decor et l'image de commencement*/
int deco(int x,char url[]){
  int t,a=1,etat=1;
  fondImage(x);
  ChoisirCouleurDessin(CouleurParNom("white"));
  RemplirRectangle(200,75,500,500);
  ChargerImage(url,300,175,0,0,300,300);
  ChargerImage("../images/bouton_pret.png",50,585,0,0,100,50);
  ChargerImage("../images/bouton_menu.png",750,585,0,0,100,50);
  ChoisirCouleurDessin(CouleurParNom("black"));
  DessinerRectangle(750,585,100,50);
  DessinerRectangle(50,585,100,50);
  while(a==1){
    while(SourisCliquee()){
      SourisPosition();
      if((_X>=50)&&(_X<=150)&&(_Y>=585)&&(_Y<=635)){
	a=0;
      }else if((_X>=750)&&(_X<=850)&&(_Y>=585)&&(_Y<=635)){
	return -1;
      }
    }
    if(ToucheEnAttente()){
      t=Touche();
      if(t==XK_Right){
	ChoisirCouleurDessin(CouleurParNom("black"));
	DessinerRectangle(50,585,100,50);
	ChoisirCouleurDessin(CouleurParNom("red"));
	DessinerRectangle(750,585,100,50);
	etat=2;
      }else if(t==XK_Left){
	ChoisirCouleurDessin(CouleurParNom("red"));
	DessinerRectangle(50,585,100,50);
	ChoisirCouleurDessin(CouleurParNom("black"));
	DessinerRectangle(750,585,100,50);
	etat=1;
      }else if(t==XK_Return){
	if(etat==1){
	  a=0;
	}else{
	  return -1;
	}
      }
    }
  }
  fondImage(x);
  ChargerImage("../images/bouton_abandon.png",400,585,0,0,100,50);
  return 1;
}

/*fonction de parametrage de l'affichage de la fenetre de commencement Taquin*/
int mdj(char nom[],int x,int y){
  int id=0;
  int b;
  int grille[10][10];
  char url2[]="../images/sangoku.png";
  char url1[]="../images/bulma.png";
  char url3[]="../images/piccolo.png";
  x+=2;
  y+=2;  
  reback(x,y,grille);
  if(strcmp(nom,"bulma")==0){
		
    b=deco(1,url1);
    if(b==-1){
      return 1;
    }
    id=1;
    plateau(x,y,grille,url1,id);
  }
  else if(strcmp(nom,"piccolo")==0){
    
    b=deco(3,url3);
    if(b==-1){
      return 1;
    }		
    id=3;
    plateau(x,y,grille,url3,id);
  }else if(strcmp(nom,"goku")==0){
		
    
    b=deco(2,url2);
    if(b==-1){
      return 1;
    }
    id=2;
    plateau(x,y,grille,url2,id);
  }

  return 1;
}

