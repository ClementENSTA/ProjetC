#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "audioread.h"
#include "stft.h"
#include "outils_maths.h"



void ligne_csv(char* nom_f_audio, FILE* f_csv, int genre){

	// LECTURE DU FICHIER AUDIO, CREATION DU TABLEAU DES ECHANTILLONS

	int frequence;
	int taille;
	int* p_freq = &frequence;
	int* p_taille = &taille;
	double* wav_data = audioread(nom_f_audio, p_freq, p_taille);


	// STFT DU SIGNAL

	int windowSize = 512;
	int hop_size = 512;
	int samples = (taille/(windowSize/2))*((windowSize/2)+1);
	double* magnitude = malloc(samples * sizeof(double));
	printf("frequence: %d\n", frequence);
	printf("taille: %d\n", taille);
	
	stft(wav_data, samples, windowSize, hop_size, magnitude, frequence, taille);
			//printf("Premières valeurs de magnitude : %f, %f, %f\n", magnitude[0], magnitude[1], magnitude[2]);
	
	
	// COMPRESSION 1D ET ÉCRITURE DANS LE FICHIER CSV

	/* écriture du label correspondant au genre musical */
	fprintf(f_csv, "%d, ", genre);
	
	/* boucle de calcul/écriture pour chaque ligne */
	int k;
	int n_colonnes = (taille/(windowSize/2));
	int n_lignes = ((windowSize/2)+1);
	double* pointeur_ligne;
	//double ligne_actuelle[n_colonnes];
	printf("nombre de colonnes dans le csv, %d\n", (windowSize+2));
	
	for(k=0; k<((windowSize/2)+1); k++){
		
		pointeur_ligne = &magnitude[k];
		double* mu_et_sigma = mu_sigma(pointeur_ligne, n_colonnes, n_lignes);
		
		fprintf(f_csv, "%.2f, %.2f, ", mu_et_sigma[0], mu_et_sigma[1]); 
		
		free(mu_et_sigma);
		
	} /* for(k=0; k<((windowSize/2)+1); k++) */
	
	fprintf(f_csv, "\n"); 
	free(wav_data);
	free(magnitude);



}


