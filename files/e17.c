//Gabriel Siqueira Silva - 20203008814
//Programa que utiliza a matriz criada no exercício 16 para realizar tarefas de distância
/*
Lógica - Como é necessário uma função, nela deve conter a quantidade de cidades que uma determinada pessoa perambulou e as cidades que foram visitadas, no entanto, como a matriz está salva num arquivo, ele deve ser passado como um parâmetro, para que as informações das distâncias entre cidades sejam utilizadas. Dessa forma criou-se a função que terá o retorno inteiro, que é a distância total.

Funcionamento da função - Como estamos trabalhando com um arquivo binário é necessário passar suas informações para um local mais fácil para ler, ou seja, uma matriz que comportará as informações do arquivo através do fread().

Nota: Quando se digita, cidade 1, implicitamente calcula-se como cidade 0 pois, por mais que a matriz descrita começa em 1, a interpretação lógica de início da matriz é em 0, dessa forma, todas as cidades estão deslocadas, portanto, uma viagem da cidade 1 -> 2 representa na matriz arquivada, uma viagem da cidade 0 -> 1.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int distancia (FILE* arquivo, int* v, int qtd); //Função para cálculo de distância entre cidades

int main(){

    FILE* matriz;
    int i,z;
    int cidades[10]; //vetor para agrupar o número das cidades
    int dist; //variável que receberá a distância total percorrida pelo usuário
    printf("Por quantas cidades voce perambulou? ");
    scanf("%d",&z);
    for(i=0;i<z;i++){
        printf("Digite o nome da %da cidade: ",i+1);
        scanf("%d",&cidades[i]);
    }
    dist = distancia(matriz, cidades, z);

    printf("Voce passou por essas cidades: ");
    for (i=0;i<z;i++){ //Para fins de formação no prompt de comando
        if(i==z-1)
            printf("%d ",cidades[i]);
        else
            printf("%d -> ",cidades[i]);
    }
    printf("percorrendo uma distancia de %d Km\n", dist);

    return 0;
}

int distancia (FILE* arquivo, int* v, int qtd){
    arquivo = fopen("matriz.txt","rb"); //Abertura de um arquivo binário
    if (arquivo == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    int a,b; //Irão receber v[i] e v[i+1] que representam as duas cidades que serão comparadas para assim chegar a uma distância
    int distTotal=0;
    int i,j; //Contadores de repetição
    int buffer[5][5]; //Representação "visualizável" do arquivo binário
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            fread(&buffer[i][j],sizeof(int),1,arquivo); //Lê do arquivo e grava no vetor
        }
    }
    if (qtd==1){
        return 0; //Permanência na mesma cidade
    }
    else{
        for (i=0;i<qtd-1;i++){
            a=v[i]-1;// -1 se deve a formatação da matriz e a formatação realizada por esse programa. Na imagem dada pelo exercício a matriz começa em 1,1; no entanto, a representação realizada para resolver o problema começa em 0,0. Portanto, comparações do tipo 1,2 tem a mesma representação de 0,1
            b=v[i+1]-1;
            distTotal=distTotal+buffer[a][b];
        }
    }
    fclose(arquivo); //Fecha o arquivo
    return distTotal; //Retorno inteiro
}
