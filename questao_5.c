
/***************************************************************
Trabalho Computacional – Programação II – 2022/1 – Ciência/Engenharia da Computação
Grupo: <Calebe Carias Degenário> e <Guilherme Lima dos Anjos>
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int pontuacao(char c){ //Funcao para verificar se o caracter é uma pontuacao
    char pontuacoes[] = ".,;:!?"; //string com todos os sinais de pontuacao para comparar
    int i;
    for(i=0;i<strlen(pontuacoes);i++){ //percorre a sring
        if(c == pontuacoes[i]){ //caso o caracter seja igual a alguma pontuaçao
            return 1; //retona 1
        }
    }
    return 0; // se nao tiver nada igual na string pontuaçoes retorna 0

}

int main() {
	FILE *arq;//Inicializa variavel que recebe o arquivo
	FILE *n_arq;
	char nomeArquivo[30],novo_arquivo[40] = "",c;
    int i=0;

    printf("Digite o nome do arquivo: "); //Pede o nome do arquivo que será criado
    scanf("%s",nomeArquivo); // Armaneza na variavel nomeArquivo
    arq = fopen(nomeArquivo, "r"); //Abre o arquivo
    if (arq==NULL) { //Verifica se foi possivel abrir o arquivo
        printf("Nao foi possivel abrir o arquivo.");
        exit(1);
	}

    while(nomeArquivo[i]!= '.'){ //Enquanto nao achar o . no nome do arquivo
        novo_arquivo[strlen(novo_arquivo)]  = nomeArquivo[i]; //copia caracter por caracter ao final da string novo_arquivo
        i++;//incrementa 1 a variavel i
    }
    strcat(novo_arquivo,"_versao2"); //Concatena o nome com _versao2 como pedido no exercicio
    for(i;i<strlen(nomeArquivo);i++){
        novo_arquivo[strlen(novo_arquivo)]  = nomeArquivo[i]; //adiciona a extensao ao final do nome
    }
	n_arq = fopen(novo_arquivo, "wt"); //cria o novo arquivo
    if (n_arq==NULL) { //Verifica se foi possivel abrir o arquivo
        printf("Nao foi possivel abrir o arquivo.");
        exit(1);
	}
    c = getc(arq); //Pega o primeiro caracter do arquivo

    while (c!=EOF){ //Laço enquanto não foi identificado o fim do arquivo
        if(pontuacao(c)== 1){ //caso a funcao retorne 1 significando que c é um sinal de pontuacao
            fputc(' ',n_arq); //adiciona um espaço em branco no arquivo
        }
        else{
            fputc(c,n_arq);//se não adiciona o proprio c
        }
        c = getc(arq); //Pega o proximo caracter
	}
	fclose(arq);//Fecha o arquivo
	fclose(n_arq); //Fecha o arquivo

	return 0;
}


