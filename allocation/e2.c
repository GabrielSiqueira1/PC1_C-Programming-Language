//Gabriel Siqueira Silva - 20203008814
/*
Explicação:

1 - Complementação da lógica do exercício número 1

Neste exercício, se pede o complemento da atividade anterior de forma que agora o usuário terá a liberdade de adicionar mais valores do que os propostos no primeiro do exercício através da função realloc, dessa forma sabemos os parâmetros da função preenchimento será o endereço do tamanho, já que este será alterado a partir da execução bem como o endereço de memória do vetor, para que seja retornado para a função principal. Dessa forma, após inserir todos os números no ponteiro alocDim é impresso no prompt de comando o que o usuário digitou e assim o programa pergunta ao usuário se esse quer adicionar mais alguns números. Quem irá receber esses valores é a variável qtdAmpliada, declarada na função, que receberá apenas a quantidade a mais que será armazenada, se o vetor original haviam 8 e o usuário quer um tamanho de 10 ele digitará 2 (qtdAmpliada=2), caso não queira, ele irá adicionar 0 números, dessa forma digitando 0 no prompt de comando não será adicionado nenhuma posição a mais no vetor e o retorno será o vetor sem a adição de mais posições, diferentemente, para qualquer número digitado diferente de 0,  o vetor terá o tamanho pré definido na função main somado com a quantidade que o usuário digitou, dessa forma realizando um realloc e armazenando o valor no conteúdo do ponteiro tamanho que corresponde ao n da função principal, após, pedindo ao usuário os novos números nas novas posições, e por fim, a função exibe o novo vetor, retorna-o e finaliza a execução; o endereço de n (MAIN) já foi utilizado e seu conteúdo foi alterado

2 - Função main

Na função principal quem irá receber o preenchimento é o ponteiro p, que já estará alterado e o tamanho dele será o novo n, também alterado na função preenchimento a partir do seu endereço
*/

#include <stdio.h>
#include <stdlib.h>

int * preenchimento(int * vetor, int * tamanho); //Uma função que retornará um vetor

int main(){

    int cM; //Contador específico para a função principal
    int n; //n elementos do meu vetor dinâmico, quantidade inicial
    int * p; //p é o ponteiro que referencia inteiros e dessa forma armazenará esse tipo de dado, como p não está inicializado, apenas declarado, o ponteiro irá apontar para um lugar indefinido
    printf("Quantos valores voce deseja digitar? ");
    scanf("%d",&n); //Armazenamento da quantidade de valores no endereço de memória de n, um fluxo de entrada

    p = (int *)realloc(NULL,n*sizeof(int)); //Realocação de memória a partir de um setor vazio, equivale ao malloc, armazenagem em tempo de execução utilizando ponteiro

    printf("\n");
    p = preenchimento(p,&n); //Chamada da função com dois parâmetros, o endereço da posição inicial do vetor criado dinamicamente, que é determinada pelo seu nome ou pela primeira posição p[0], e o endereço do tamanho a fim de que seja alterado o tamanho durante a execução da função
    printf("\n");

    //Impressão na função principal
    printf("Os numeros utilizados para preencher foram (MAIN): ");
    for(cM=0;cM<n;cM++){ //Impressão das posições 0 até n-1
        if(cM==n-1) //Quebra de linha na impressão em linha
            printf("%d\n",p[cM]);
        else
            printf("%d ",p[cM]);
    }

    p = (int *)realloc(p,0); //Liberação da memória alocada

    return 0;
}

int * preenchimento(int * alocDim, int * tamanho){
    int n = *tamanho; //Variável que receberá o conteúdo do ponteiro para que a alocação seja feita de um ponto inexistente ao limite, não começando do 0
    int cP; //Contador específico para a função preenchimento
	int qtdAmpliada; //Variável que será retornada, deverá complementar tanto o tamanho anterior bem como a alteração que o usuário irá realizar
    int i = 1; //Inteiro auxliador. Ele irá acompanhar a quantidade de números digitados para informar ao usuário quantos números já foram digitados
    for(cP=0;cP<*tamanho;cP++){ //Ocupação das posições 0 até tamanho-1
        printf("%do numero: ",i);
        scanf("%d",&alocDim[cP]);
        i++;
    }
	printf("Os numeros utilizados para preencher foram: ");
    for(cP = 0;cP<*tamanho;cP++){ //Impressão das posições 0 até tamanho-1
        if(cP == *tamanho-1)
            printf("%d\n",alocDim[cP]);
        else
            printf("%d ",alocDim[cP]);
    }
    printf("Deseja adicionar mais algum valor? Em caso de negativo digite 0, porem se afirmativo, quantos elementos a mais voce deseja armazenar no vetor? ");
    scanf("%d",&qtdAmpliada);
	*tamanho=qtdAmpliada+*tamanho;
    if (qtdAmpliada == 0){
        //Impressão dentro da função
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
        alocDim = (int *) realloc(alocDim,(*tamanho)*sizeof(int)); //Adição de posições à alocação dinâmica
        for(cP = n;cP<(*tamanho);cP++){//Adição de novos números a partir dos já existentes
            printf("%do numero: ",i);
            scanf("%d",&alocDim[cP]);
            i++;
        }
        //Impressão dentro da função
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
