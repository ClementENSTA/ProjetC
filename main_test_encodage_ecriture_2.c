#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "audioread.h"
#include "outils_maths.h"
#include "ligne_csv.h"

#define TRUE 1 
#define FALSE 0



int main() {


	FILE* f_csv = fopen("features.csv", "a+");
	
	if(f_csv == NULL)
		{ printf("Erreur dans la création / ouverture du fichier csv\n");
		  return 1; }
	
	
	/* Boucle d'écriture par genre */
	
	char* liste_genre[10] = {"./librairie_audio/blues", "./librairie_audio/classical", "./librairie_audio/country", "./librairie_audio/disco", "./librairie_audio/hiphop", "./librairie_audio/jazz", "./librairie_audio/metal", "./librairie_audio/pop", "./librairie_audio/reggae", "./librairie_audio/rock",};
	int k,q;
	char* chaine_1 = ".0000";
	char* chaine_2 = ".000";
	char* chaine_3 = ".wav";
	char* tempo = malloc(40*sizeof(char));
	char* tempo_2 = malloc(1*sizeof(char));
	char* tempo_3 = malloc(2*sizeof(char));
	
	for(k=0; k<10; k++) {
	
		printf("encodage du genre %d\n", k);


		for(q=0; q<100; q++){
			
			strcpy(tempo, liste_genre[k]);
			//printf("numero %d\n", q);
			//printf("titre : %s\n", tempo);
			
			if(q<10){
				strcat(tempo, chaine_1);
				//printf("titre : %s\n", tempo);
				sprintf(tempo_2, "%d", q);
				//printf("tempo2 : %s\n", tempo_2);
				strcat(tempo, tempo_2);
				//printf("titre : %s\n", tempo);
				strcat(tempo, chaine_3);	
			}
			else{
				strcat(tempo, chaine_2);
				sprintf(tempo_3, "%d", q);
				strcat(tempo, tempo_3);
				strcat(tempo, chaine_3);
			}
			printf("titre : %s\n\n", tempo);
			
			ligne_csv (tempo, f_csv, k);
			
		} /* for(q=0; q<100; q++) */
		
	} /* for(k=0; k<10; k++) */
	
	printf("Ecriture terminee !\n");
	free(tempo);
	free(tempo_2);
	free(tempo_3);

	return 0;

}
