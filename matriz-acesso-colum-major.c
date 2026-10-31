#include <stdio.h>
#include <stdlib.h>

int ** create_int_matrix(int nrows, int ncols){
	int** m  = (int**) calloc(nrows, sizeof(int*));
	
	for(int i = 0; i < nrows; i++){
		m[i] = (int*) calloc(ncols, sizeof(int));
	}
	return m;
}

int main(int argc, char **argv){
    int nrows = 100000;
    int ncols = 10000;

    int **m = create_int_matrix(nrows, ncols);
    
    //começando pelas colunas
    for(int j = 0; j < ncols; j++){
        for(int i = 0; i < nrows; i++){
            m[i][j] = (i + j) % 2;
        }
    }
    return 0;
}