//Gabriel Siqueira Silva - 20203008814
//Programa que escreve num arquivo bin�rio, as informa��es de uma matriz
/*
L�gica - Atrav�s de uma matriz pr�-definida, fwrite escreve os dados no arquivo bin�rio da seguinte forma, fwrite(de onde vem, o tamanho ocupado, quantidade armazenada, para onde vai), at� armazenar todos os dados no arquivo, por�m como iremos saber se dentro do arquivo h� a matriz?
Para exibir o conte�do do arquivo, dever� ser no prompt de comando, utilizaremos fread que funcionar� da seguinte forma fread(para onde vai, o tamanho ocupado, quantidade armazenada, para onde vai), dessa forma as informa��es v�o para uma nova matriz declarada no pr�rprio programa e sendo uma matriz, essa poder� ser exibida.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *matriz;
    int Mat[5][5]={00,15,30,05,12,15,00,10,17,28,30,10,00,03,11,05,17,03,00,80,12,28,11,80,00};
    int buffer[5][5]; //Matriz que ser� vizualizada no prompt de comando. Como um arquivo bin�rio � muito complicado de ler, � vi�vel, atrav�s da fread(), ler o arquivo e passar para um vetor, no caso, o buffer.
    matriz = fopen("matriz.txt","wb");
    if (matriz == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    int i,j; //Contadores para repeti��es
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fwrite(&Mat[i][j],sizeof(int),1,matriz); //Escreve o conte�do da matriz no arquivo bin�rio
        }
    }
    printf("Arquivo matriz.txt foi gerado!\n");
    fclose(matriz); //Fecha o arquivo. Para realizar outras opera��es, ou seja, uma novamente o arquivo, devemos fechar ou chamar o arquivo da forma w+, que representa uma forma de escrever e ler um arquivo
    matriz = fopen("matriz.txt","rb"); //Leitura de um arquivo bin�rio
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fread(&buffer[i][j],sizeof(int),1,matriz); //L� do arquivo e grava no vetor
        }
    }
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            printf("%d ",buffer[i][j]); //Exibe o vetor buffer. Esse tem o mesmo conte�do do arquivo
        }
        printf("\n");
    }
    fclose(matriz);
    return 0;
}
