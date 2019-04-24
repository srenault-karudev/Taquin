/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include "victoire.h"


/*fonction de verification de victoire*/
int verif(int t1,int t2,int grille[][10]){
 
	int i,j,x=1;
	for(i=1;i<t1-1;i++){
		for(j=1;j<t2-1;j++){
			if(grille[i][j]!=x){
				return 0;
			}
			x++;
		}
	}
	return 1;
}


/*fonction qui montre au joueur qu'il a gagner*/
void aff_victoire(int compt,int id){
  char str[255];
  int t,etat=1;
  if(id==1){
    ChargerImage("../images/fin_bulma.png",0,0,0,0,900,650);
  }else if(id==2){
    ChargerImage("../images/fin_sangoku.png",0,0,0,0,900,650);
  }else if(id==3){
    ChargerImage("../images/fin_piccolo.png",0,0,0,0,900,650);
  }
  ChoisirCouleurDessin(CouleurParNom("black"));;
  sprintf(str,"%d",compt);
  EcrireTexte(550,495,str,2);
	
  DessinerRectangle(20,580,190,53);
  DessinerRectangle(670,580,190,53);
  while(1){
    while(!SourisCliquee()){
      if(ToucheEnAttente()){
	t=Touche();
	if(t==XK_Right){
	  ChoisirCouleurDessin(CouleurParNom("black"));
	  DessinerRectangle(20,580,190,53);
	  ChoisirCouleurDessin(CouleurParNom("red"));
	  DessinerRectangle(670,580,190,53);
	  etat=2;
	}else if(t==XK_Left){
	  ChoisirCouleurDessin(CouleurParNom("red"));
	  DessinerRectangle(20,580,190,53);
	  ChoisirCouleurDessin(CouleurParNom("black"));
	  DessinerRectangle(670,580,190,53);
	  etat=1;
	}else if(t==XK_Return){
	  if(etat==1){
	    return;
	  }else{
	    FermerGraphique();
	    exit(1);
	  }
	}
      }
    }
    SourisPosition();
    if((_X>=20)&&(_X<=210)&&(_Y>=580)&&(_Y<=633)){
      return ;
    }else if((_X>=670)&&(_X<=860)&&(_Y>=580)&&(_Y<=633)){
      FermerGraphique();
      exit(1);
    }
  }
}


