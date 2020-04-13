// Inclure stdio.h pour les entrées / sorties standard.
#include<stdio.h>
#include<stdlib.h>
#include "Fonction_De_Cryptage.h"

int main()
{
    printf(" **********   **********  **********  **********   **********\n");
    printf("              AES : Advanced Encryption Standard \n");
    printf(" **********   **********  **********  **********   **********\n\n");

    FILE* fichierCle = NULL;
    fichierCle = OuvrirFichier(1);

	// Recevoir la longueur de la clé.
	while(Nr!=128 && Nr!=192 && Nr!=256)
	{
		printf("\nEnter la langueur de la cle ( 128, 192 ou bien 256 ): ");
		scanf("%d",&Nr);
	}

	// Calculer Nk et Nr.
	Nk = Nr / 32;
	Nr = Nk + 6;

	int i = 0;
	for( i=0 ; i<Nk*4 ; i++ )
	{
		fscanf(fichierCle, "%02x", &Key[i]);
	}
    fclose(fichierCle);

    printf("\nKey de cryptage : \n");
	for( i=0 ; i<Nk*4 ; i++ )
	{
		printf("%02x ",Key[i]);
	}
	printf("\n");

	// La routine KeyExpansion doit être appelée avant chiffrement.
	KeyExpansion();
    printf("\nSous-cles de cryptage : \n");
    for( i=0; i<240 ; i++)
	{
	    if( i%16 == 0 || i==0) { printf("\n"); }
		printf("%02x " , RoundKey[i]);
	}
	printf("\n\n");

    FILE* fichierBlocClair = NULL;
    fichierBlocClair = OuvrirFichier(2);
	for( i=0 ; i<Nb*4 ; i++ )
	{
		fscanf(fichierBlocClair, "%02x", &in[i]);
	}

	// Lancer le cryptage.
	Cipher();

	printf("\nTexte avant l'operation de cryptage : \n");
	for( i=0 ; i<Nb*4 ; i++ )
	{
		printf("%02x ",in[i]);
	}
	printf("\n");

	// Output the encrypted text.
	printf("\nTexte apres l'operation de cryptage :\n");
	for( i=0 ; i<Nb*4 ; i++ )
	{
		printf("%02x ",out[i]);
	}
	printf("\n\n");

    fclose(fichierBlocClair);
}
