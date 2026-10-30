#include <stdio.h>
#include <stdlib.h> //contém o NULL, calloc, malloc, free

int main (){
    //alocação de um vetor estático (memória stack)
    int vs[5] = {0, 10, 20, 30, 40};

    puts("### VETOR ESTATICO");
    printf("&vs = %p vs = %p\n", &vs, vs);
    for(int i = 0; i < 5; i++){
        printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
    }

    puts("\n");
 
    //alocação de um vetor dinâmico usando malloc (memória heap)

    int* vh_mal = malloc(5*sizeof(int)); //todos os elementos possuem lixo

    printf("&vh_mal = %p vh_mal = %p\n", &vh_mal, vh_mal);
    for(int i = 0; i < 5; i++){
        printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
    }
    puts("\n");

    //alocação de um vetor dinâmico usando calloc (memória heap)
    //todo o bloco alocado possui bits 0,
    //garante que todos os elementos alocados (do vetor) terão valor 0

    int* vh_cal = calloc(5, sizeof(int)); //todos os elementos possuem lixo

    printf("&vh_cal = %p vh_cal = %p\n", &vh_cal, vh_cal);
    for(int i = 0; i < 5; i++){
        printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
    }
    puts("\n");

    //NÃO ESTAMOS DESALOCANDO OS VETORES

 //0530MPnmf23:!
    return 0;
}