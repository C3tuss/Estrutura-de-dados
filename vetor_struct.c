#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

#define TAM 3

struct tipo_pessoa{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){
    setlocale(LC_ALL, "Portuguese");

    tipo_pessoa lista[3];

    for(int i = 0; i < TAM; i++){
        printf("Insira os dados da pessoa %d:\n", i+1);
        puts("Nome: ");
        scanf(" %50[^\n]s", &lista[i].nome);
        fflush(stdin);

        puts("Idade: ");
        scanf("%d", &lista[i].idade);
        fflush(stdin);

        puts("Peso: ");
        scanf("%f", &lista[i].peso);
        fflush(stdin);
    }

    system("cls"); //apaga a tela

    puts("Seus dados:\n");

    for(int i = 0; i < TAM; i++){
        printf("---------- Pessoa %d -----------\n", i+1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tIdade: %d\n", lista[i].idade);
        printf("\tPeso: %.2f\n", lista[i].peso);
    }
    printf("-----------------------------\n");
    return 0;
}