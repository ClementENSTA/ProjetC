#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "ligne_vect_x.h"
#include "outils_maths.h"


int main(int argc, char* argv[]){

	if (argc != 2) {
		printf("Erreur : nombre d'arguments invalide\n");
		return 1;
	}
	
	char* nom_f_audio = argv[2];
	
	// RECUPERATION DE LA MATRICE W ET DU VECTEUR B
	char* nom_f_matrice = "matrice_w.csv";
	char* nom_f_vecteur = "vecteur_b.csv";
	int n = 10;
	int p = 514;
	
	double w[n][p];
	read_array(nom_f_matrice, n, w);
	
	double b[n];
	read_vector(nom_f_vecteur, n, b);
	
	
	// RECHERCHE DU MAXIMUM DE CORRESPONDANCE
	
	double* x = ligne_vect_x(nom_f_audio);
	
	/* opération matricielle, et recherche du maximum de correspondance */
	double res[n];
	operation_matricielle(n, p, w, b, x, res);
	int i_max = indice_maximum(res,n);
	
	char* liste_genre[10] = {"du blues", "de la musique classique", "de la country", "du disco", "du hiphop", "du jazz", "du metal", "de la pop", "du reggae", "du rock",};
	
	printf("Cet extrait est %s\n", liste_genre[i_max]);

	/* libération des mémoires alloués */
	free(x);
	return 0;
	
}
