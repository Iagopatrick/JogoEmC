#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **AlocaTabuleiro(int linhas, int colunas){
    char **M;
    int i, j;

    M = (char **) malloc (linhas * sizeof(char *));
    
    if(M == NULL){
        printf("Erro, memoria insuficiente!");
        exit (1);
    } 
    
    for (i = 0; i < linhas; i++){
        M[i] = (char *) malloc (colunas * sizeof(char));
        if(M[i] == NULL){
            printf("Erro, memoria insuficiente!");
            exit (1);
        } 
    }
    
    return M;
}

char *AlocaVetor(int colunas){
    char *v;
    v = (char *) malloc (colunas * sizeof(char));
    if(v == NULL){
        printf("Erro, memoria insuficiente!");
        exit(1);
    }
    return v;
}

int main(){
    int linhas, colunas, i, j;
    char **tabuleiro, *Vetor;
    colunas = 2;
    Vetor = AlocaVetor(colunas);
    scanf("%s", Vetor);
    printf("%s", Vetor);
}