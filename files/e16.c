//Gabriel Siqueira Silva - 20203008814
//Programa que escreve num arquivo binário, as informações de uma matriz
/*
Lógica - Através de uma matriz pré-definida, fwrite escreve os dados no arquivo binário da seguinte forma, fwrite(de onde vem, o tamanho ocupado, quantidade armazenada, para onde vai), até armazenar todos os dados no arquivo, porém como iremos saber se dentro do arquivo há a matriz?
Para exibir o conteúdo do arquivo, deverá ser no prompt de comando, utilizaremos fread que funcionará da seguinte forma fread(para onde vai, o tamanho ocupado, quantidade armazenada, para onde vai), dessa forma as informações vão para uma nova matriz declarada no prórprio programa e sendo uma matriz, essa poderá ser exibida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *matriz;
    int Mat[5][5]={00,15,30,05,12,15,00,10,17,28,30,10,00,03,11,05,17,03,00,80,12,28,11,80,00};
    int buffer[5][5]; //Matriz que será vizualizada no prompt de comando. Como um arquivo binário é muito complicado de ler, é viável, através da fread(), ler o arquivo e passar para um vetor, no caso, o buffer.
    matriz = fopen("matriz.txt","wb");
    if (matriz == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    int i,j; //Contadores para repetições
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fwrite(&Mat[i][j],sizeof(int),1,matriz); //Escreve o conteúdo da matriz no arquivo binário
        }
    }
    printf("Arquivo matriz.txt foi gerado!\n");
    fclose(matriz); //Fecha o arquivo. Para realizar outras operações, ou seja, uma novamente o arquivo, devemos fechar ou chamar o arquivo da forma w+, que representa uma forma de escrever e ler um arquivo
    matriz = fopen("matriz.txt","rb"); //Leitura de um arquivo binário
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fread(&buffer[i][j],sizeof(int),1,matriz); //Lê do arquivo e grava no vetor
        }
    }
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf("%d ",buffer[i][j]); //Exibe o vetor buffer. Esse tem o mesmo conteúdo do arquivo
        }
        printf("\n");
    }
    fclose(matriz);
    return 0;
}
