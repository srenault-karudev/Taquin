/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generateur.h"
/*fonction de mise a zero du tableau */
void zero(int grille[][10]){
	int i,j;
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			grille[i][j]=0;
		}
	}
}

/*fonction de decallage de valeur dans un tableau en fonction d'une valeur de base*/
void reback(int l,int h,int grille[][10]){
	int i,j,nb=0,alea,s,x,y;
	int pos[2];
	zero(grille);
	srand(time(NULL));
	for(i=1;i<l-1;i++){
		for(j=1;j<h-1;j++){
			nb++;
			grille[i][j]=nb;
		}
	}
	pos[0]=1;
	pos[1]=1;
	nb=0;
	while(nb<100){
		alea=rand()%4+1;
		if(alea==1){
			y=0;
			x=-1;
		}else if(alea==2){
			y=-1;
			x=0;
		}else if(alea==3){
			y=0;
			x=1;
		}else if(alea==4){
			y=1;
			x=0;
		}else{
			perror("erreur random");
			y=0;
			x=0;
		}
		if(grille[pos[0]+y][pos[1]+x]!=0){
			s=grille[pos[0]+y][pos[1]+x];
			grille[pos[0]+y][pos[1]+x]=1;
			grille[pos[0]][pos[1]]=s;
			pos[0]+=y;
			pos[1]+=x;
		}
		nb++;
	}
}
 
