/* Auteur : Pierre villiers et Steven Renault*/
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include "parametre.h"
#include "decoupage.h"
#include "mdj.h"

/*fonction qui permet d'affecter une couleur soit noir ou rouge a un rectangle
en fonction dunumero qui definira les rectangles rouge pour les images de 0-3 , les lignes de 3-8 et les colonne de 9-14 
 */
void Selection(int s,char color){
  
  if(color=='r'){
    ChoisirCouleurDessin(CouleurParNom("red"));
  }else{
    ChoisirCouleurDessin(CouleurParNom("black"));
  }
  /*image*/
  if(s==0){

    DessinerRectangle(42,184,219,236);
  }
  if(s==1){
    DessinerRectangle(347,185,219,233);
  }
  if(s==2){
    DessinerRectangle(655,184,219,235);
  }
  /*ligne*/
  if(s==3){               
    DessinerRectangle(25,183,80,73);
  }
  if(s==4){
    DessinerRectangle(129,183,80,73);
  }
  if(s==5){
    DessinerRectangle(238,183,80,73);
  }
  if(s==6){
    DessinerRectangle(337,183,79,73);
  }
  if(s==7){
    DessinerRectangle(436,183,80,73);
  }
  if(s==8){
    DessinerRectangle(550,183,78,73);
  }
  /*colonne*/
  if(s==9){
    DessinerRectangle(25,451,80,72);
  }
  if(s==10){
    DessinerRectangle(129,451,80,72);
  }
  if(s==11){
    DessinerRectangle(233,451,80,72);
  }
  if(s==12){
    DessinerRectangle(336,451,80,72);
  }
  if(s==13){
    DessinerRectangle(440,451,80,72);
  }
  if(s==14){
    DessinerRectangle(544,451,80,72);
  }
  return;
}


/* fonction qui permet de choisir les dimensions  en fonction des position avec la souris ou bien au clavier*/
int SelectDimension(int image,char tab[],int etat){
  

  int ligne=0;
  int colonne=0;
  int t;
  int select=3;
  int donne[2];
  int choix=1;
  
  /*ligne*/
  Selection(3,'r');
  Selection(4,'b');
  Selection(5,'b');
  Selection(6,'b');
  Selection(7,'b');
  Selection(8,'b');
  /*colonne*/
  Selection(9,'r');
  Selection(10,'b');
  Selection(11,'b');
  Selection(12,'b');
  Selection(13,'b');
  Selection(14,'b');

  
  while(ligne==0){	
    while(colonne==0){
      while(!SourisCliquee()){

	if(etat==1||etat==2){
	  if(ToucheEnAttente()){
	    t=Touche();
	 
	    if(choix==1){
	      if((t==XK_Right) && (select<8)){
		Selection(select,'b');
		select++;
		Selection(select,'r');
		choix=1;
	      }
	      else if((t==XK_Left) && (select>3)){
		Selection(select,'b');
		select--;
		Selection(select,'r');
		choix=1;
	      }
	    
	      else if(t==XK_Return){
		donne[0]=select;
		select=9;
		Selection(9,'r');
		choix=2;
	       
	      }
	    }
	    else{
	     
	      if((t==XK_Right) && (select<14)){
		Selection(select,'b');
		select++;
		Selection(select,'r');
	       
	      }
	      else if((t==XK_Left) && (select>9)){
		Selection(select,'b');
		select--;
		Selection(select,'r');
	  
	      }
	      else if(t==XK_Return){
		donne[1]=select-6;
	
		choix=4;
	    	break;
	      }
	      else if(t==XK_Escape){
		choix=1;	    
	      }
	    }
	  }

	}
    
      }
  

	SourisPosition();
	if(choix==4){
	  ligne=donne[0];
	  colonne=donne[1];
	  
	}
	
	else if ((image==1) || (image==2) || (image==3)){
	    if(_X>=25 && _X<=105 && _Y>=183 && _Y<=256){
	   
	    ligne=3;
	  }	  
	  if(_X>=129 && _X<=209 && _Y>=183 && _Y<=256){
	         
	  
	    ligne=4;	      
	  }
	  if(_X>=238 && _X<=318 && _Y>=183 && _Y<=256){
        
	    ligne=5;	        
	  }
	  if(_X>=337 && _X<=412 && _Y>=183 && _Y<=256){
	  
	 
	    ligne=6; 
	  }
	  if(_X>=436 && _X<=516 && _Y>=183 && _Y<=256){
	 
	    ligne=7;     
	  }
	  if(_X>=550 && _X<=628 && _Y>=183 && _Y<=256){
	  
	  
	    ligne=8;	     
	  }
	    
	  if(ligne!=0){
	    if(_X>=25 && _X<=105 && _Y>=451 && _Y<=523){
        
	      EffacerEcran(CouleurParNom("white"));
 
	      colonne=3;
	    }
	    if(_X>=129 && _X<=209 && _Y>=451 && _Y<=523){
	   
	      EffacerEcran(CouleurParNom("white"));  
	   
	      colonne=4;
	    }
	    if(_X>=233 && _X<=313 && _Y>=451 && _Y<=523){
	  
	      EffacerEcran(CouleurParNom("white"));  
	 
	      colonne=5;
	    }
	    if(_X>=336 && _X<=416 && _Y>=451 && _Y<=523){
	 
	      EffacerEcran(CouleurParNom("white"));  
	    
	      colonne=6;
	    }
	    if(_X>=440 && _X<=520 && _Y>=451 && _Y<=523){
	   
	      EffacerEcran(CouleurParNom("white"));  
	    
	      colonne=7;
	    }
	    if(_X>=544 && _X<=624 && _Y>=451 && _Y<=523){
	      EffacerEcran(CouleurParNom("white"));  
	  
	      colonne=8;
	    }
	  }


	}
      
      }
      
    }
   mdj(tab,ligne,colonne);
   return 1;
  }
  


/* fonction qui permet de choisir une image en fonction de sa position avec la souris ou bien au clavier */
  int  SelectImage(void){
    int image=0;
    int select=1;
    int s=0;
    int t;
    int etat=0;

    Selection(0,'b');
    Selection(2,'b');  
    Selection(1,'r');
    while(image==0){
      while(!SourisCliquee()){
	if(ToucheEnAttente()){
	  s=1;
	  t=Touche();	

	  if(t==XK_Right && (select!=2)){
	    Selection(select,'b')	;	            	              
	    select++;
	    Selection(select,'r');
	  }					
	  else if(t==XK_Left && (select!=0)){	
	    Selection(select,'b');
	    select--;
	    Selection(select,'r');
	  }						
	  else if(t==XK_Return){
	    etat=2;
	    break;	 
	  }

	}
      }
   			   
      SourisPosition();

      if((_X>=42 && _X<=261 && _Y>=184 && _Y<=420)||((select==0)&&(s==1))){

	char tab[]={'b','u','l','m','a'};
	EffacerEcran(CouleurParNom("white"));
	ChargerImageFond("../images/choix dimension.png");    
	image=1;
	SelectDimension(image,tab,etat);
	return 1;
      }

	if((_X>=347 && _X<=566 && _Y>=185 && _Y<=418)||((select==1)&&(s==1))){
	char tab[]={'g','o','k','u','\0'};
	EffacerEcran(CouleurParNom("white"));
	ChargerImageFond("../images/choix dimension.png");
	image=2;
	SelectDimension(image,tab,etat);
	return 1 ;
      }

	if((_X>=655 && _X<=874 && _Y>=184 && _Y<=419)||((select==2)&&(s==1))){
	char tab[]={'p','i','c','c','o','l','o'};
	EffacerEcran(CouleurParNom("white"));
	ChargerImageFond("../images/choix dimension.png");
	image=3;
	SelectDimension(image,tab,etat);     
	return 1;
      }
           
    }
    return 1;
  }




