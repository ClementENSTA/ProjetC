#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "audioread.h"
#include "stft.h"
#include "outils_maths.h"



void ligne_vect_x(char* nom_f_audio){

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
	
	
	// COMPRESSION 1D ET ÉCRITURE DANS LE FICHIER CSV
	
	/* creation du tableau de sortie */
	double* x = malloc((windowSize+2) * sizeof(double));
	
	/* boucle de calcul/écriture pour chaque ligne */
	int k;
	int n_colonnes = (taille/(windowSize/2));
	int n_lignes = ((windowSize/2)+1);
	double* pointeur_ligne;

	
	for(k=0; k<((windowSize/2)+1); k++){
		
		pointeur_ligne = &magnitude[k];
		double* mu_et_sigma = mu_sigma(pointeur_ligne, n_colonnes, n_lignes);
		
		x[k] = mu_et_sigma[0];
		x[k+1] = mu_et_sigma[1];
		
		free(mu_et_sigma);
		
	} /* for(k=0; k<((windowSize/2)+1); k++) */
	
	free(wav_data);
	free(magnitude);
	return x;
}



