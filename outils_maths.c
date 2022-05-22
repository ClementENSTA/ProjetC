#include <math.h>
#include <stdlib.h>
#include <stdio.h>


// Fonction donnant un tableau à deux cases, contenant dans cet ordre la moyenne et l'écart-type du tableau.
double* mu_sigma(double* t, int n_col, int n_lignes){

	double S = 0;
	double carre_S = 0;
	
	int k;
	for(k=0; k<n_col; k++) {
		S = S + t[k*n_lignes];
		carre_S = carre_S + ((t[k*n_lignes]) * (t[k*n_lignes]));
	}


	double alpha = (carre_S/n_col) - ((S*S)/(n_col*n_col));

	double sigma = sqrt(alpha);
	
	double* t_sortie = malloc(2*sizeof(double));
	t_sortie[0] = (S/n_col);
	t_sortie[1] = sigma;
	
	return t_sortie;

}

