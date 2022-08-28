//Gabriel Siqueira Silva - 20203008814
/*
Explica��o:

1 - Complementa��o da l�gica do exerc�cio n�mero 1

Neste exerc�cio, se pede o complemento da atividade anterior de forma que agora o usu�rio ter� a liberdade de adicionar mais valores do que os propostos no primeiro do exerc�cio atrav�s da fun��o realloc, dessa forma sabemos os par�metros da fun��o preenchimento ser� o endere�o do tamanho, j� que este ser� alterado a partir da execu��o bem como o endere�o de mem�ria do vetor, para que seja retornado para a fun��o principal. Dessa forma, ap�s inserir todos os n�meros no ponteiro alocDim � impresso no prompt de comando o que o usu�rio digitou e assim o programa pergunta ao usu�rio se esse quer adicionar mais alguns n�meros. Quem ir� receber esses valores � a vari�vel qtdAmpliada, declarada na fun��o, que receber� apenas a quantidade a mais que ser� armazenada, se o vetor original haviam 8 e o usu�rio quer um tamanho de 10 ele digitar� 2 (qtdAmpliada=2), caso n�o queira, ele ir� adicionar 0 n�meros, dessa forma digitando 0 no prompt de comando n�o ser� adicionado nenhuma posi��o a mais no vetor e o retorno ser� o vetor sem a adi��o de mais posi��es, diferentemente, para qualquer n�mero digitado diferente de 0,  o vetor ter� o tamanho pr� definido na fun��o main somado com a quantidade que o usu�rio digitou, dessa forma realizando um realloc e armazenando o valor no conte�do do ponteiro tamanho que corresponde ao n da fun��o principal, ap�s, pedindo ao usu�rio os novos n�meros nas novas posi��es, e por fim, a fun��o exibe o novo vetor, retorna-o e finaliza a execu��o; o endere�o de n (MAIN) j� foi utilizado e seu conte�do foi alterado

2 - Fun��o main

Na fun��o principal quem ir� receber o preenchimento � o ponteiro p, que j� estar� alterado e o tamanho dele ser� o novo n, tamb�m alterado na fun��o preenchimento a partir do seu endere�o
*/

#include <stdio.h>
#include <stdlib.h>

int * preenchimento(int * vetor, int * tamanho); //Uma fun��o que retornar� um vetor

int main(){

    int cM; //Contador espec�fico para a fun��o principal
    int n; //n elementos do meu vetor din�mico, quantidade inicial
    int * p; //p � o ponteiro que referencia inteiros e dessa forma armazenar� esse tipo de dado, como p n�o est� inicializado, apenas declarado, o ponteiro ir� apontar para um lugar indefinido
    printf("Quantos valores voce deseja digitar? ");
    scanf("%d",&n); //Armazenamento da quantidade de valores no endere�o de mem�ria de n, um fluxo de entrada

    p = (int *)realloc(NULL,n*sizeof(int)); //Realoca��o de mem�ria a partir de um setor vazio, equivale ao malloc, armazenagem em tempo de execu��o utilizando ponteiro

    printf("\n");
    p = preenchimento(p,&n); //Chamada da fun��o com dois par�metros, o endere�o da posi��o inicial do vetor criado dinamicamente, que � determinada pelo seu nome ou pela primeira posi��o p[0], e o endere�o do tamanho a fim de que seja alterado o tamanho durante a execu��o da fun��o
    printf("\n");

    //Impress�o na fun��o principal
    printf("Os numeros utilizados para preencher foram (MAIN): ");
    for(cM=0;cM<n;cM++){ //Impress�o das posi��es 0 at� n-1
        if(cM==n-1) //Quebra de linha na impress�o em linha
            printf("%d\n",p[cM]);
        else
            printf("%d ",p[cM]);
    }

    p = (int *)realloc(p,0); //Libera��o da mem�ria alocada

    return 0;
}

int * preenchimento(int * alocDim, int * tamanho){
    int n = *tamanho; //Vari�vel que receber� o conte�do do ponteiro para que a aloca��o seja feita de um ponto inexistente ao limite, n�o come�ando do 0
    int cP; //Contador espec�fico para a fun��o preenchimento
	int qtdAmpliada; //Vari�vel que ser� retornada, dever� complementar tanto o tamanho anterior bem como a altera��o que o usu�rio ir� realizar
    int i = 1; //Inteiro auxliador. Ele ir� acompanhar a quantidade de n�meros digitados para informar ao usu�rio quantos n�meros j� foram digitados
    for(cP=0;cP<*tamanho;cP++){ //Ocupa��o das posi��es 0 at� tamanho-1
        printf("%do numero: ",i);
        scanf("%d",&alocDim[cP]);
        i++;
    }
	printf("Os numeros utilizados para preencher foram: ");
    for(cP = 0;cP<*tamanho;cP++){ //Impress�o das posi��es 0 at� tamanho-1
        if(cP == *tamanho-1)
            printf("%d\n",alocDim[cP]);
        else
            printf("%d ",alocDim[cP]);
    }
    printf("Deseja adicionar mais algum valor? Em caso de negativo digite 0, porem se afirmativo, quantos elementos a mais voce deseja armazenar no vetor? ");
    scanf("%d",&qtdAmpliada);
	*tamanho=qtdAmpliada+*tamanho;
    if (qtdAmpliada == 0){
        //Impress�o dentro da fun��o
		printf("Os numeros utilizados para preencher foram (PREENCHIMENTO): ");
        for(cP = 0;cP<*tamanho;cP++){
            if(cP == *tamanho-1)
                printf("%d\n",alocDim[cP]);
            else
                printf("%d ",alocDim[cP]);
            }
        return alocDim;
    }
    else{
        alocDim = (int *) realloc(alocDim,(*tamanho)*sizeof(int)); //Adi��o de posi��es � aloca��o din�mica
        for(cP = n;cP<(*tamanho);cP++){//Adi��o de novos n�meros a partir dos j� existentes
            printf("%do numero: ",i);
            scanf("%d",&alocDim[cP]);
            i++;
        }
        //Impress�o dentro da fun��o
		printf("Os numeros utilizados para preencher foram (PREENCHIMENTO): ");
        for(cP = 0;cP<*tamanho;cP++){
            if(cP == *tamanho-1)
                printf("%d\n",alocDim[cP]);
            else
                printf("%d ",alocDim[cP]);
            }
        return alocDim;
        }
    }
