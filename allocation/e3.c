//Gabriel Siqueira Silva - 20203008814
/*
Explicação:

1 - Função main

A função main deve ser explicada pois as variáveis presentes nessa sessão servirão de armazenagem para todo o código; estas são o ponteiro q que armazenará o endereço do vetor gerado e o inteiro tamanho que cuidará do valor disposto pelo usuário para tal, o seu endereço é passado como parâmetro para a primeira função. Ainda na função, existem três funções internas que são executadas na ordem: criar_vetor -> exibir_vetor -> limpeza de memória, onde a primeira receberá o endereço do inteiro tamanho como parâmetro, a segunda receberá o resultado do primeiro juntamente com o endereço do novo tamanho disponibilizado pelo usuário e a terceira receberá apenas o resultado da primeira função para limpar a alocação.

2 - Lógica proposta

Função * criar_vetor: Após a chamada na função main ocorre a execução da função criar_vetor, ela dispõe de um inteiro i que auxiliará no scanf e dará suporte a interface no prompt de comando, um inteiro n que é responsável pelo tamanho do vetor e um ponteiro p que irá desenvolver um vetor dinâmicamente, a partir desse momento inicia-se a interação com o usuário, e esse determinando o tamanho do vetor, que em seguida o ponteiro tam, que é parâmetro da função (ele está representando o endereço do tamanho da função main), deverá receber o valor de n para que este seja passado para as outras funções, nesse sentido indica-se por *tam = n, a armazenagem do valor de n como conteúdo do ponteiro tam, pois *tam representa o conteúdo do ponteiro, assim, após o armazenamento, o ponteiro p é inicializado e assim ocorre a repetição (for) para gerar o preenchimento, que por escolha, deverá ser realizado pelo usuário. Segue o retorno do ponteiro p, para que na função main o ponteiro q receba o endereço e dessa forma tenha todas as informações digitadas pelo usuário que serão impressas na próxima função.
Função * exibir_vetor: Executado após a chamada a partir da função main, essa função que dispõe de dois parâmetros irá exibir o vetor a partir da informação do ponteiro, dessa forma o ponteiro t tem o endereço do tamanho do vetor que por sua vez teve seu valor alterado na função criar_vetor assumindo o valor de n, dessa forma *t também tem o valor de n, e isso auxiliará na impressão do vetor no prompt de comando a partir de um sistema de repetição. Por escolha a função retorna endereço do vetor exibido.
Função * liberar_vetor: Uma função simples, realizada ao final da execução do exibir_vetor por parte da função main. Nesta é necessário apenas o parâmetro de um ponteiro que terá o mesmo endereço do ponteiro da função main e dessa forma, o vetor iniciado/criado será zerado.
*/

#include <stdio.h>
#include <stdlib.h>

int * criar_vetor(int *tam); //Uma função que cria um vetor, juntamente estabelece o número de itens adicionado e retorna função e internamente, como ele receberá um ponteiro para tamanho, ocorrerá um armazenamento da grandeza do vetor
int * exibir_vetor(int *vetor,int *t); //Exibe o vetor a partir do valor do retorno da primeira função
int * liberar_vetor (int * vetor2); //Função que retorna o ponteiro com endereço NULL

int main(){

    int * q; //Ponteiro que irá receber o resultado da função criar_vetor, ou seja, esse terá o endereço de memória da alocação dinâmico criado dentro da função
    int tamanho; //Inteiro que irá comportar o tamanho do vetor criado dentro da função criar_vetor
    q=criar_vetor(&tamanho); //Parâmetros: tamanho (endereço para armazenar o digito do usuário)
    exibir_vetor(q,&tamanho); //Parâmetros: endereço do vetor criado e o endereço do tamanho estabelecido pelo usuário
    liberar_vetor(q); //Parâmetros: endereço do vetor (limpeza de memória)
    return 0;
}

int * criar_vetor(int *tam){
    int i; //Inteiro que coordena a contagem
    int n; //Inteiro que receberá o tamanho indicado pelo usuário
    int * p; //Ponteiro que será iniciado para ser desenvolvido dinâmicamente
    printf("Qual sera o tamanho do vetor? ");
    scanf("%d",&n);
    *tam = n; //O ponteiro tam aponta para inteiros, dessa maneira ele armazenará o valor de n
    p = (int *)realloc(NULL,n*sizeof(int)); //Inicialização do ponteiro
    printf("\n");
    for (i=0;i<n;i++){
        printf("%do numero: ",(i+1));
        scanf("%d",&p[i]);
    }
    return p; //Retorna um ponteiro
}
int * exibir_vetor(int *vetor,int *t){
    int i;
    printf("\nO vetor contem: ");
    for(i=0;i<*t;i++){
        if(i==*t-1)
            printf("%d\n",vetor[i]);
        else
            printf("%d ",vetor[i]);
    }
    return vetor; //Retorno de um ponteiro
}
int * liberar_vetor (int * vetor2){
    free(vetor2);
    return vetor2; //Retorno de um ponteiro
}
