//Gabriel Siqueira Silva - 20203008814
/*
Explicação:

1 - Funcao main

O programa começa a sua execução a partir da função main e nessa são declarados dois inteiros, um contador e representado por cM, um numero de posicoes, n, e um ponteiro para inteiros, p, que auxiliara na alocação dinâmica. A interação com o usuário começa ao exibir no prompt de comando quantos valores o usuário deseja digitar e a resposta será armazenada na variável n. A partir desse momento a alocação dinâmica será iniciada através do realloc que utiliza n como variável para determinar o tamanho inicial do array gerado pelo ponteiro. Dessa forma é chamada a função preenchimento que irá completar o vetor.

2 - Função preenchimento

Após receber dois parâmetros, o endereço da primeira posição do vetor, dessa forma alocDim=p, e o tamanho que usuário deseja contemplar, assim tamanho=n, ocorre a declaração de um contador, determinado cP, e a inicialização de um auxiliador, i, que apenas irá coordenar a interface no prompt de comando, para auxiliar a visualização. Com a inicialização, declaração e a passagem de parâmetro passamos para a lógica do programa.

2.1 - Lógica da Função preenchimento

A partir de um processo de repetição com o for, o contador cP irá assumir o valor 0 representando a primeira posição do vetor, dessa forma ele deverá variar até tamanho-1 pois se o vetor é de tamanho 4 por exemplo, o preenchimento deve ser feito na ordem de 0,1,2,3, representando 4 itens, a partir disso, valores digitados pelo usuário serão armazenados nas posições de alocDim e esta função retorna um ponteiro que aponta para o endereço da primeira posição de alocDim.

3. Função main

O ponteiro determinado na função main (p), receberá alocDim por meio da função e assim, quando ocorrer a impressão de p, esse irá imprimir os mesmos valores digitados pelo usuário pois p tem o mesmo endereço de alocDim. Finaliza-se com um realloc para zerar a memória, esse realloc recebe o ponteiro e o deixa com 0 posições, dessa maneira, zerando a memória.
*/

#include <stdio.h>
#include <stdlib.h>

int * preenchimento(int * alocDim, int tamanho); //Uma função que irá retornar um ponteiro, neste caso, a primeira posição do vetor alocDim

int main(){

    int cM; //Contador específico para a função principal
    int n; //n elementos do meu vetor dinâmico
    int * p; //p é o ponteiro que referencia inteiros e dessa forma armazenará esse tipo de dado, como p não está inicializado, apenas declarado, o ponteiro irá apontar para um lugar indefinido
    printf("Quantos valores voce deseja digitar? ");
    scanf("%d",&n); //Armazenamento da quantidade de valores no endereço de memória de n, um fluxo de entrada

    p = (int *)realloc(NULL,n*sizeof(int)); //Realocação de memória a partir de um setor vazio, armazenagem em tempo de execução utilizando ponteiro

    printf("\n");
    p = preenchimento(p,n); //Chamada da função com dois parâmetros, o endereço da posição inicial do vetor criado dinamicamente, que é determinada pelo seu nome ou pela primeira posição p[0], e o seu tamanho n
    printf("\n");

    //Impressão na função principal
    printf("Os numeros utilizados para preencher foram: ");
    for(cM=0;cM<n;cM++){ //Impressão das posições 0 até n-1
        if(cM==n-1) //Quebra de linha na impressão em linha
            printf("%d\n",p[cM]);
        else
            printf("%d ",p[cM]);
    }

    p = (int *)realloc(p,0); //Liberação da memória alocada

    return 0;
}

int * preenchimento(int * alocDim, int tamanho){ 
    int cP; //Contador específico para a função preenchimento
    int i = 1; //Inteiro auxliador. Ele irá acompanhar a quantidade de números digitados para informar ao usuário quantos números já foram digitados
    for(cP=0;cP<tamanho;cP++){ //Ocupação das posições 0 até tamanho-1
        printf("%do numero: ",i);
        scanf("%d",&alocDim[cP]);
        i++;
    }
    return alocDim;
}

