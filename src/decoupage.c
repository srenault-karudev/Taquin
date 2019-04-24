/* Auteur : Pierre villiers et Steven Renault*/

#include <stdio.h>
#include <stdlib.h>
#include "decoupage.h"


/*fonction qui va calculer les cordonnées de chaque image et
les mettre dans un tableau en fonction de des dimensions et de l’image
*/
void decoupage (int ligne,int colonne,int tab[][4]){
  int i,j,posX=0,posY=0;
  int x,y;
  int dimension=1;
  x=300/(colonne-2);
  y=300/(ligne-2);
  
  

tab[0][0]=0;
tab[0][1]=0;
tab[0][2]=0;
tab[0][3]=0;
  for(i=0;i<ligne-2;i++){
    for(j=0;j<colonne-2;j++){
       if(dimension==1){
	tab[dimension][0]=0;
	tab[dimension][1]=0;
	tab[dimension][2]=0;
	tab[dimension][3]=0;
	posX+=x;
      }else{
	tab[dimension][0]=posX;
	tab[dimension][1]=posY;
	tab[dimension][2]=x;
	tab[dimension][3]=y;
	posX+=x;
      }
dimension++;
    }
    posX=0;
    posY+=y;
  }
}

