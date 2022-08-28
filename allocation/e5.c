//Gabriel Siqueira Silva - 20203008814
/*
Explicação:

Lógica do programa: O programa não inicia na função main e sim nos structs pois a própria função main as utiliza, dessa forma as estruturas são cadastradas para que o programa esteja mais limpo e mais intuitivo, assim, CPF, DATANASC e PESSOA são as três estruturas das quais duas (CPF, DATANASC) estão contidas em uma (PESSOA).

1 - Função main

Estabelece o ponteiro do tipo estrutura, então quando iniciado em seu interior já há um espaço para nome, DATANASC e CPF, e sua iniciação, dada por um malloc, depende da quantidade garantida pelo usuário que está armazenada na variável n e a partir disso é chamado a função preencher.

2 - Função preencher

De forma intuitiva, a função preenche acessando os locais da estrutura, e dessa forma P[i].nome acessa o conteúdo do ponteiro P em sua estrutura PESSOA no char nome e isso acontece pois strings já guardam endereço de memória, assim não é necessário utilizar &, diferentemente de P[i].data.dia que para passar o endereço deve-se colocar &, pois, sem esse o que acessamos é o valor da variável e isso não é desejável num scanf. Para fazer o preenchimento devemos realizá-lo em camadas, dessa forma, para preencher a data de nascimento devemos iniciar o endereço do ponteiro &P[i] e como &P[i] faz parte da estrutura PESSOA, podemos acessar qualquer valor interno a partir de um ponto, dessa forma &P[i].data eu acesso o endereço da variável data que faz parte de outra estrutura, a estrutura DATANASC que subdivide em 3 inteiros e o acesso a eles requer mais um ponto. Dessa forma &P[i].data.ano ocorre o acesso ao endereço de memória do ano da pessoa cadastrada e essa mesma lógica pode ser repetida para as outras estruturas como a CPF. A função repete seu procedimento de acordo com a quantidade de pessoas cadastradas (qtd) que é o valor n inicializado na função main. No fim retorna o ponteiro estruturado e completo.

3 - Função exibir 

Utilizando o ponteiro do main que neste momento comporta o resultado da função preencher, a exibição ocorre com base na repetição que utiliza o parâmetro qtd que recebe a quantidade de pessoas cadastradas (n da função main).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct cadastro{ //Estrutura para o cadastro de pessoa física
    int cadastro1,cadastro2,cadastro3,cadastro4;
} CPF;

typedef struct ano{ //Estrutura para a data de nascimento
    int dia,mes,ano;
}DATANASC;

typedef struct dados{ //Estrutura geral que interliga as outras estruturas
    char nome[200];
    DATANASC data;
    CPF pf;
}PESSOA;

PESSOA * preencher(PESSOA * P,int qtd); //Função que retornará o endereço do ponteiro, retorno do tipo estrutura
int exibir(PESSOA * P,int qtd); //Função que não terá retorno pois a exibição deve ser feita dentro da função

PESSOA * preencher(PESSOA * P,int qtd){
    int i; //Contador interno
    for (i=0;i<qtd;i++){
        getchar(); //Utilizado para armazenar o ENTER após a chamada da função e repetição do processo
        printf("Digite o nome: ");
        fgets(P[i].nome,200,stdin);
        printf("Digite a data de nascimento: ");
        scanf("%d/%d/%d",&P[i].data.dia,&P[i].data.mes,&P[i].data.ano);
        printf("Digite o CPF (com pontos e hifen): ");
        scanf("%d.%d.%d-%d",&P[i].pf.cadastro1,&P[i].pf.cadastro2,&P[i].pf.cadastro3,&P[i].pf.cadastro4);
    }
    return P;
}

int exibir(PESSOA * P,int qtd){
    int i;
    printf("Dados:\n");
    for (i=0;i<qtd;i++){
        printf("Nome completo: %s",P[i].nome);
        printf("Data de nascimento: %d/%d/%d\n",P[i].data.dia,P[i].data.mes,P[i].data.ano);
        printf("CPF: %d.%d.%d-%d\n",P[i].pf.cadastro1,P[i].pf.cadastro2,P[i].pf.cadastro3,P[i].pf.cadastro4);
    }
    return 0;
}

int main(){
    PESSOA *p; //Ponteiro que tem o tipo PESSOA (uma estrutura)
    int n; //Inteiro que indica a quantidade de pessoas que serão adicionadas
    printf("Quantas pessoas serao adicionadas? ");
    scanf("%d",&n);
    p = (PESSOA *) malloc(n*sizeof(PESSOA));
    p = preencher(p,n);
    exibir(p,n);
    free(p);
}
