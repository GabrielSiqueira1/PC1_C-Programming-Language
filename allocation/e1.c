//Gabriel Siqueira Silva - 20203008814
/*
Explica��o:

1 - Funcao main

O programa come�a a sua execu��o a partir da fun��o main e nessa s�o declarados dois inteiros, um contador e representado por cM, um numero de posicoes, n, e um ponteiro para inteiros, p, que auxiliara na aloca��o din�mica. A intera��o com o usu�rio come�a ao exibir no prompt de comando quantos valores o usu�rio deseja digitar e a resposta ser� armazenada na vari�vel n. A partir desse momento a aloca��o din�mica ser� iniciada atrav�s do realloc que utiliza n como vari�vel para determinar o tamanho inicial do array gerado pelo ponteiro. Dessa forma � chamada a fun��o preenchimento que ir� completar o vetor.

2 - Fun��o preenchimento

Ap�s receber dois par�metros, o endere�o da primeira posi��o do vetor, dessa forma alocDim=p, e o tamanho que usu�rio deseja contemplar, assim tamanho=n, ocorre a declara��o de um contador, determinado cP, e a inicializa��o de um auxiliador, i, que apenas ir� coordenar a interface no prompt de comando, para auxiliar a visualiza��o. Com a inicializa��o, declara��o e a passagem de par�metro passamos para a l�gica do programa.

2.1 - L�gica da Fun��o preenchimento

A partir de um processo de repeti��o com o for, o contador cP ir� assumir o valor 0 representando a primeira posi��o do vetor, dessa forma ele dever� variar at� tamanho-1 pois se o vetor � de tamanho 4 por exemplo, o preenchimento deve ser feito na ordem de 0,1,2,3, representando 4 itens, a partir disso, valores digitados pelo usu�rio ser�o armazenados nas posi��es de alocDim e esta fun��o retorna um ponteiro que aponta para o endere�o da primeira posi��o de alocDim.

3. Fun��o main

O ponteiro determinado na fun��o main (p), receber� alocDim por meio da fun��o e assim, quando ocorrer a impress�o de p, esse ir� imprimir os mesmos valores digitados pelo usu�rio pois p tem o mesmo endere�o de alocDim. Finaliza-se com um realloc para zerar a mem�ria, esse realloc recebe o ponteiro e o deixa com 0 posi��es, dessa maneira, zerando a mem�ria.
*/

#include <stdio.h>
#include <stdlib.h>

int * preenchimento(int * alocDim, int tamanho); //Uma fun��o que ir� retornar um ponteiro, neste caso, a primeira posi��o do vetor alocDim

int main(){

    int cM; //Contador espec�fico para a fun��o principal
    int n; //n elementos do meu vetor din�mico
    int * p; //p � o ponteiro que referencia inteiros e dessa forma armazenar� esse tipo de dado, como p n�o est� inicializado, apenas declarado, o ponteiro ir� apontar para um lugar indefinido
    printf("Quantos valores voce deseja digitar? ");
    scanf("%d",&n); //Armazenamento da quantidade de valores no endere�o de mem�ria de n, um fluxo de entrada

    p = (int *)realloc(NULL,n*sizeof(int)); //Realoca��o de mem�ria a partir de um setor vazio, armazenagem em tempo de execu��o utilizando ponteiro

    printf("\n");
    p = preenchimento(p,n); //Chamada da fun��o com dois par�metros, o endere�o da posi��o inicial do vetor criado dinamicamente, que � determinada pelo seu nome ou pela primeira posi��o p[0], e o seu tamanho n
    printf("\n");

    //Impress�o na fun��o principal
    printf("Os numeros utilizados para preencher foram: ");
    for(cM=0;cM<n;cM++){ //Impress�o das posi��es 0 at� n-1
        if(cM==n-1) //Quebra de linha na impress�o em linha
            printf("%d\n",p[cM]);
        else
            printf("%d ",p[cM]);
    }

    p = (int *)realloc(p,0); //Libera��o da mem�ria alocada

    return 0;
}

int * preenchimento(int * alocDim, int tamanho){ 
    int cP; //Contador espec�fico para a fun��o preenchimento
    int i = 1; //Inteiro auxliador. Ele ir� acompanhar a quantidade de n�meros digitados para informar ao usu�rio quantos n�meros j� foram digitados
    for(cP=0;cP<tamanho;cP++){ //Ocupa��o das posi��es 0 at� tamanho-1
        printf("%do numero: ",i);
        scanf("%d",&alocDim[cP]);
        i++;
    }
    return alocDim;
}

