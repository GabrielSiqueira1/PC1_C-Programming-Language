//Gabriel Siqueira Silva - 20203008814
//Programa que utiliza a matriz criada no exerc�cio 16 para realizar tarefas de dist�ncia
/*
L�gica - Como � necess�rio uma fun��o, nela deve conter a quantidade de cidades que uma determinada pessoa perambulou e as cidades que foram visitadas, no entanto, como a matriz est� salva num arquivo, ele deve ser passado como um par�metro, para que as informa��es das dist�ncias entre cidades sejam utilizadas. Dessa forma criou-se a fun��o que ter� o retorno inteiro, que � a dist�ncia total.

Funcionamento da fun��o - Como estamos trabalhando com um arquivo bin�rio � necess�rio passar suas informa��es para um local mais f�cil para ler, ou seja, uma matriz que comportar� as informa��es do arquivo atrav�s do fread().

Nota: Quando se digita, cidade 1, implicitamente calcula-se como cidade 0 pois, por mais que a matriz descrita come�a em 1, a interpreta��o l�gica de in�cio da matriz � em 0, dessa forma, todas as cidades est�o deslocadas, portanto, uma viagem da cidade 1 -> 2 representa na matriz arquivada, uma viagem da cidade 0 -> 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distancia (FILE* arquivo, int* v, int qtd); //Fun��o para c�lculo de dist�ncia entre cidades

int main(){

    FILE* matriz;
    int i,z;
    int cidades[10]; //vetor para agrupar o n�mero das cidades
    int dist; //vari�vel que receber� a dist�ncia total percorrida pelo usu�rio
    printf("Por quantas cidades voce perambulou? ");
    scanf("%d",&z);
    for(i=0;i<z;i++){
        printf("Digite o nome da %da cidade: ",i+1);
        scanf("%d",&cidades[i]);
    }
    dist = distancia(matriz, cidades, z);

    printf("Voce passou por essas cidades: ");
    for (i=0;i<z;i++){ //Para fins de forma��o no prompt de comando
        if(i==z-1)
            printf("%d ",cidades[i]);
        else
            printf("%d -> ",cidades[i]);
    }
    printf("percorrendo uma distancia de %d Km\n", dist);

    return 0;
}

int distancia (FILE* arquivo, int* v, int qtd){
    arquivo = fopen("matriz.txt","rb"); //Abertura de um arquivo bin�rio
    if (arquivo == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    int a,b; //Ir�o receber v[i] e v[i+1] que representam as duas cidades que ser�o comparadas para assim chegar a uma dist�ncia
    int distTotal=0;
    int i,j; //Contadores de repeti��o
    int buffer[5][5]; //Representa��o "visualiz�vel" do arquivo bin�rio
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fread(&buffer[i][j],sizeof(int),1,arquivo); //L� do arquivo e grava no vetor
        }
    }
    if (qtd==1){
        return 0; //Perman�ncia na mesma cidade
    }
    else{
        for (i=0;i<qtd-1;i++){
            a=v[i]-1;// -1 se deve a formata��o da matriz e a formata��o realizada por esse programa. Na imagem dada pelo exerc�cio a matriz come�a em 1,1; no entanto, a representa��o realizada para resolver o problema come�a em 0,0. Portanto, compara��es do tipo 1,2 tem a mesma representa��o de 0,1
            b=v[i+1]-1;
            distTotal=distTotal+buffer[a][b];
        }
    }
    fclose(arquivo); //Fecha o arquivo
    return distTotal; //Retorno inteiro
}
