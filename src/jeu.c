/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "jeu.h"

/*fonction de selection de la case par l'utilisateur*/
int jeu(int t1,int t2,int grille[][10]){
  int i,j,x,y,t,a=0;
  int n,b=1;
  int c=t1-2;
  int d=t2-2;
  int e=300/c;
  int f=300/d;
  int m1=((c+(c%2))*4)/2;
  int m2=((d+(d%2))*4)/2;
  int save[2];
  
  for(i=1;i<c+1;i++){
    for(j=1;j<d+1;j++){
      if(grille[i][j]==1){
	save[0]=i;
	save[1]=j;
	i=c+1;
	j=d+1;
      }
    }
  }
  i=save[0];
  j=save[1];
    
  x=300-m2;
  y=175-m1;
    
  while(a==0){
    


    while(!SourisCliquee()){
      /*Partie de la selection clavier*/
      if(ToucheEnAttente()){
		t=Touche();
		if((t==XK_Left)&&(grille[i][j-1]!=0)){
		        n=grille[i][j-1];
	  		grille[i][j-1]=grille[i][j];
	  		grille[i][j]=n;
			i=c;
	  		j=d;
	  		a=1;
	  		b=0;
			break;
		}else if((t==XK_Right)&&(grille[i][j+1]!=0)){
		  n=grille[i][j+1];
	  		grille[i][j+1]=grille[i][j];
	  		grille[i][j]=n;
	  		i=c;
	  		j=d;
	  		a=1;
	  		b=0;
			break;
		}else if((t==XK_Up)&&(grille[i-1][j]!=0)){
		  n=grille[i-1][j];
	  		grille[i-1][j]=grille[i][j];
	  		grille[i][j]=n;
	  		i=c;
	  		j=d;
	  		a=1;
	  		b=0;
			break;
		}else if((t==XK_Down)&&(grille[i+1][j]!=0)){
		  n=grille[i+1][j];
	  		grille[i+1][j]=grille[i][j];
			grille[i][j]=n;
	  		i=c;
	  		j=d;
	  		a=1;
	  		b=0;
			break;
		}	
      }


    }
    if(b==1){
      SourisPosition();
      if(i!=1){
	if((_X>=x+(e*(j-1))+(4*(j-1))&&(_X<=x+(e*j)+(4*j))&&(_Y>=y+(f*(i-2))+(4*(i-2)))&&(_Y<=y+(f*(i-1))+(4*(i-1))))){
	  n=grille[i-1][j];
	  grille[i-1][j]=grille[i][j];
	  grille[i][j]=n;
	  a=1;
	}
      }
      if(j!=1){
	if((_X>=x+(e*(j-2))+(4*(j-2))&&(_X<=x+(e*(j-1))+(4*(j-1)))&&(_Y>=y+(f*(i-1))+(4*(i-1)))&&(_Y<=y+(f*i)+(4*i)))){
	  n=grille[i][j-1];
	  grille[i][j-1]=grille[i][j];
	  grille[i][j]=n;
	  a=1;
	}
      }
      if(i!=c){
	if((_X>=x+(e*(j-1))+(4*(j-1)))&&(_X<=x+(e*j)+(4*j))&&(_Y>=y+(f*i)+(4*i))&&(_Y<=y+(f*(i+1))+(4*(i+1)))){
	  
	  n=grille[i+1][j];
	  grille[i+1][j]=grille[i][j];
	  grille[i][j]=n;
	  a=1;
	}
      }
      if(j!=d){
	if((_X>=x+(e*j)+(4*j))&&(_X<=x+(e*(j+1))+(4*(j+1)))&&(_Y>=y+(f*(i-1))+(4*(i-1)))&&(_Y<=y+(f*i)+(4*i))){
	  n=grille[i][j+1];
	  grille[i][j+1]=grille[i][j];
	  grille[i][j]=n;
	  a=1;
	}
      }  

	 
	
      if((_X>=400)&&(_X<=500)&&(_Y>=585)&&(_Y<=635)){
	return 2;
      }
    }
    
  }
  /*Bouton d'abandon*/
    
   
  return 0;
}
