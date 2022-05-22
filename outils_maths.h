double* mu_sigma(double* t, int n_col, int n_lignes);

void read_array(char filename[], int n, double arr[][n]);

void read_vector(char filename[], int n, double* arr);

void operation_matricielle(int n, int p ,double w[][p], double* b, double* x, double* res);

int indice_maximum(double* l, int n);
