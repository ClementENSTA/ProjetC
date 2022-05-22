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




void read_array(char filename[], int n, double arr[][n])
{
    FILE* fp = fopen(filename, "r");
    //double arr[10][514];
    if (!fp)
        printf("Can't open file\n");
 
    else {
        char buffer[4096];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     4096, fp)) {
            column = 0;
            char* value = strtok(buffer, ", ");
            while (value) {
                arr[row][column] = atof(value);
                value = strtok(NULL, ", ");
                column++;
            }
            row++;
        }
        fclose(fp);
    }
}


void read_vector(char filename[], int n, double* arr)
{
    FILE* fp = fopen(filename, "r");
    if (!fp)
        printf("Can't open file\n");
 
    else {
        char buffer[4096];
 
        int row = 0;
        int column = 0;
 
        while (fgets(buffer,
                     4096, fp)) {
            column = 0;
            char* value = strtok(buffer, ", ");
            while (value) {
                arr[row][column] = atof(value);
                value = strtok(NULL, ", ");
                column++;
            }
            row++;
        }
        fclose(fp);
    }
}



void operation_matricielle(int n, int p ,double w[][p], double* b, double* x, double* res) {
	/* n est le nombre de genres musicaux, donc de lignes de la matrice ; c'est donc également la taille de b et de res */
	/* p est le nombre d'échantillons, donc de colonnes de la matrice ; c'est également la taille de x */
	
	double somme_sur_j;
	int i,j;
	
	for(i=0; i<n; i++) {
	
		somme_sur_j = b[i];
		
		for(j=0; j<p; j++) {
		
			somme_sur_j = somme_sur_j + ((w[i][j]) * (x[j]));
		
			}
	
		res[i] = somme_sur_j;
		
	}
	
}

int indice_maximum(double* l, int n) {

	int i_max = 0;
	int k;
	
	for (k=1; k<n; k++) {
		if (l[k] > l[i_max]) {
			i_max = k;
		}
	}
	
	return i_max;
	
}
