#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Chaines.h"

/***************************************************************************************/
//      ouvrir un fichier dont son chemin est donnez par l'utilisateur
/***************************************************************************************/
FILE *OuvrirFichier(int choix)
{
 FILE* document = NULL;
 char chaine1[40],chaine2[150];
 switch(choix)
 {
  case 1 :  printf("Donner le nom de votre cle !\n");
            break;
  default : printf("Donner le nom de votre Bloc clair !\n");
            lireChaine(chaine1,40);
            break;
 }
 lireChaine(chaine1,40);
 printf("Donner le chemin !\n");
 lireChaine(chaine2,150);
 strcat(chaine2,chaine1);
 printf("chaine1 = %s !\n", chaine1);
 printf("chaine2 = %s !\n", chaine2);
 document = fopen(chaine2, "r+");
       if( document!=NULL )
       {
           printf("l'ouverture a ete faite avec succer !\n");
       }
       else
       {
           printf("l'ouverture a echouer !\n");
       }
       return document;
}

/***************************************************************************************/
//      Vider le buffer
/***************************************************************************************/
void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

/***************************************************************************************/
//      La lecture d'une chaine de caractère
/***************************************************************************************/
int lireChaine(char *chaine, int longueur)
{
 char *positionEntree = NULL;
 if (fgets(chaine, longueur, stdin) != NULL)   //on utulise cette fonction pour eviter "The buferOverFlowError"
  {
   positionEntree = strchr(chaine, '\n');  //on recherche le caractere <ENTRER>
   if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
   {
    *positionEntree = '\0'; // On remplace ce caractère par \0
   }
   else
   {
    viderBuffer();
   }
  }
  else
  {
   viderBuffer();
  }
}
