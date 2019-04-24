/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <string.h>
#include "plateau.h"
#include "victoire.h"
#include "jeu.h"
#include "decoupage.h"
#include "menu.h"

/*fonction qui affiche toute les partie de l'image en fonction de leur ordre dans la grille du Taquin*/
void affiche_plateau(int t1,int t2, int grille[][10],int lib[][4],char nom[]){
	int i,j,k;
	int c=t1-2;
	int d=t2-2;
	int e=300/c;
	int f=300/d;
	int m1=((c+(c%2))*4)/2;
	int m2=((d+(d%2))*4)/2;
	int ox=300-m2,oy=175-m1;
	int x=ox,y=oy;
	ChoisirCouleurDessin(CouleurParNom("white"));
  
  	RemplirRectangle(200,75,500,500);
	for(i=0;i<c;i++){
		for(j=0;j<d;j++){
			k=grille[i+1][j+1];
			ChargerImage(nom,x,y,lib[k][0],lib[k][1],lib[k][2],lib[k][3]);
			x=x+f+4;
		}
		x=ox;
		y=y+e+4;
	}
}

/*fonction qui affiche le nombre de Clic(s) /"Mouvement" fait depuis le debut de la partie*/
void affiche_compt(int compt){
	char str1[255];
	ChoisirCouleurDessin(CouleurParNom("black"));
	EcrireTexte(300,110,"Nombre(s) de clic(s) :",2);
	sprintf(str1,"%d",compt);
	EcrireTexte(425,145,str1,2);
	return;
}

/*fonction qui gère le fonctionnement du plateau de jeu*/
void plateau(int t1,int t2,int grille[][10],char nom[],int id){
        int stop=0,compt=0;
	int lib[65][4];
	decoupage(t1,t2,lib); 
	while(stop==0){
		affiche_plateau(t1,t2,grille,lib,nom);
		affiche_compt(compt);
		stop=jeu(t1,t2,grille);
		compt++;
		
		if(verif(t1,t2,grille)==1){
			stop=1;
		}
	}
	if(stop==1){
		aff_victoire(compt,id);
	}
	return;
}


