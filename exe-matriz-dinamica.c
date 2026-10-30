#include <stdio.h>
#include <stdlib.h>

int ** create_int_matrix(int nrows, int ncols){
	int** m  = (int**) calloc(nrows, sizeof(int*));
	
	for(int i = 0; i < nrows; i++){
		m[i] = (int*) calloc(ncols, sizeof(int));
	}
	return m;
}

void print_int_matrix(const int **m, int nrows, int ncols){//int *m[]
	for(int i = 0; i < nrows; i++){
		printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);
		
		for(int j = 0; j < ncols; j++){
			
			printf("&m[%d][%d] = %p, m[%d][%d] = %d\n", 
			i, j, &m[i][j],
			i, j, m[i][j]);
		}
		puts(""); 
	}
	
} 

void add_scalar_into_int_matrix(int **m, int nrows, int ncols, int scalar){
	for(int i = 0; i < nrows; i++){
		for(int j = 0; j < ncols; j++){
			m[i][j] += scalar;
		}
	}
	
}

void destroy_int_matrix(int ***mat, int nrows, int ncols){
	for(int i = 0; i < nrows; i++){
		free(mat[i]);
	}
	free(mat);
	mat = NULL;
}

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("ERROR\n%s nrows ncols scalar\n", argv[0]);
		exit(-1);
	}
	
	int nrows = atoi(argv[1]);
	int ncols = atoi(argv[2]);
	int scalar = atoi(argv[3]);
	
	//alocação da matriz
	int **m = create_int_matrix(nrows, ncols);
	
	//atribuição de alguns valores para a matriz
	int count = 0;
	for(int i = 0; i < nrows; i++){
		for(int j = 0; j < ncols; j++){
			m[i][j] = count++;
		}
	}
	
	//imptime matriz
	print_int_matrix((const int**) m, nrows, ncols);
	
	//adicionando escalar
	add_scalar_into_int_matrix(m, nrows, ncols, 10);
	print_int_matrix((const int**) m, nrows, ncols);
	
	//desalocando a matriz
	destroy_int_matrix(m, nrows, ncols);
	
	return 0;
}