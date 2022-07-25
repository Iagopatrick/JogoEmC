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


void queima(char **tabuleiro, int indice_Linha, int indice_coluna){
    int i, j;
    // preciso andar pela direita e pela esquerda. O fogo começa numa cela central, a partir dela, serão contadas
    // oito celulas da direita e oito pra esquerda. Para cima e para baixo serao oito, mas na celula seguinte passa para
    // sete células
    // ATENÇÃO: teoricamente eu precisaria de um limitador, para nao ultrapassar o tamanho da matriz
    for(i = indice_Linha - 8; i < indice_Linha + 8; i++){

        for(j = indice_coluna - 8; j < indice_coluna + 8; j++){
            if(tabuleiro[indice_Linha - i][indice_coluna - j] == 'P'){
                tabuleiro[indice_Linha - i][indice_coluna - j] = 'F';

            }
        }
    }
}

void ataque_MagoFogo(char **tabuleiro, int linhas, int colunas){}

int main(){
    int linhas, colunas, i, j;
    char **tabuleiro, *Vetor;
    
    scanf("%d %d", &linhas, &colunas);
    
    tabuleiro = AlocaTabuleiro(linhas, colunas);
    Vetor = AlocaVetor(colunas + 1);

    for(i = 0; i < linhas; i++){
        getchar();
        fgets(Vetor, colunas + 1, stdin);
        for(j = 0; j < colunas; j++){
            tabuleiro[i][j] = Vetor[j];
        }
    }


    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%c", tabuleiro[i][j]);
        }
        printf("\n");
    }
}