//Gabriel Siqueira Silva - 20203008814
/*
Explicação:

1 - Função main

Criação de três ponteiros, desses, 2 são definidos aleatoriamente e com tamanhos 12 (Q) e 20 (R), e a inicilização de ponteiro W, com um tamanho de 9*sizeof(int). A escolha desse número para inicilização se deve ao compilador utilizado. O GCC na sua versão 8.2.0 executa o programa com o W estando com apenas 1 de tamanho, no entanto, a sua versão mais atual aparentemente necessita de um maior espaço para executar e a partir de testes, iniciando com 9*sizeof(int) a execução é realizada corretamente e assim o procedimento interseção é chamado.

2 - Procedimento intersecao

Sem um retorno, esse procedimento realiza a interseção e o crescimento do tamanho do vetor, nesse caso, do ponteiro W (maiúsculo) iniciado no main e o ponteiro w (minúsculo) que tem o mesmo endereço, da seguinte forma: Percorrendo na forma de uma matriz, a função caminha por q[j], onde 0<=j<12 e dentro deste caminho acontece outro caminho, o de r[z], para 0<=z<20, onde esse funciona em ciclos, ciclos de j, assim a cada 1 aumento do j, z crescerá até 19. Dessa forma pode-se estabelecer um relação, sempre que q[j] igual r[z] algo ocorrerá, se isso acontecer pela primeira vez o primeiro realloc será realizado (essa parte é importante para o conjunto lógico seguinte, que irá estabelecer a não repetição de um item) e w terá uma posição (W[0]) que armazenará a primeira igualdade, assim w[0]=q[j], dessa forma w já terá um item que servirá de comparação com os outros, e dessa maneira, o primeiro realloc não será mais realizado e para isso, o contador2 tem seu valor alterado. Os reallocs seguintes serão realizados se q[j]==r[z] porém apenas se w[k]!=q[j], para todo 0<k<contador-1, e contador iniciando em 1 e aumentando a partir de um realloc, logo a relação de reallocs com contador é de +1; comparando os itens de w com os itens de q garante-se que w não terá itens repetidos (isso se deve a teoria de conjuntos, pois como há uma interseção, w deve estar contido em q e r). O contador que determinará se algum item pode entrar no conjunto w é a variável validade. Ao fazer a comparação com o operador de diferença, é necessário que validade seja igual ao tamanho do vetor w para que tenha certeza de que o novo número adicionado não está presente no vetor. Com a validade == contador-1, aplica-se o realloc em w aumentando o seu tamanho e esse procedimento é repetido até que j==12 interrompendo a repetição geral. Importante ressaltar que, como o tamanho é alterado o tempo inteiro dentro do programa, o endereço também é passado como parâmetro, dessa forma o tamanho final de w, contador-1, está armazenado no conteúdo do ponteiro tamanho e este remete ao endereço de receptor, o inteiro da função main.

3 - Função main

Sem retorno do procedimento, mas com alteração das variáveis e ponteiros a partir do endereço, ocorre uma condição, se receptor que é igual ao conteúdo de tamanho, ou seja, contador-1, for maior que 0 realmente há uma interseção e se faz uma repetição for, caso contrário não há repetição nem interseção.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intersecao(int * q,int * r,int * w,int * tamanho); //Não há retorno, apenas manipulações internas

int main(){
    int i; //Contador da função principal, utilizado para preenchimento de variáveis
    int *Q, *R, *W; //Ponteiros para a relação proposta em que W = Q inter R
    int receptor; //O inteiro que irá receber o tamanho do vetor a partir da função intersecao
    Q = (int *) malloc(12*sizeof(int)); //Q terá 12 posições
    R = (int *) malloc(20*sizeof(int)); //R terá 20 posições
    W = (int *) malloc(9*sizeof(int)); //Inicialização de W
    srand(time(NULL)); //Impede que a sequência de valores sejam repetidos a cada execução
    printf("Primeiro vetor: ");
    for(i=0;i<20;i++){
        R[i] = rand() % 10; //Valores aleatórios entre 0 e 99
        if(i<19){
            printf("%d ",R[i]);
        }
        else
            printf("%d\n",R[i]);
    }
    printf("Segundo vetor: ");
    for(i=0;i<12;i++){
        Q[i] = rand() % 10;
        if(i<11){
            printf("%d ",Q[i]);
        }
        else
            printf("%d\n",Q[i]);
    }
    intersecao(Q,R,W,&receptor);
    if(receptor>0){ //Condição para existência da interseção (valor: contador-1)
        printf("Intersecao dos dois vetores: ");
        for(i=0;i<receptor;i++){
            if(i<receptor-1){
                printf("%d ",W[i]);
            }
            else
                printf("%d\n",W[i]);
        }
    }
    else{
        printf("Intersecao dos dois vetores e nula\n");
    }
    free(W); //Limpeza de memória
    free(Q); //Limpeza de memória
    free(R); //Limpeza de memória
    return 0;
}

void intersecao(int * q,int * r,int * w,int * tamanho){
    int j,z,k=0;
    int validade=0; //Variável que irá auxiliar na repetição de itens dentro do vetor
    int contador=1; //Variável que contempla o aumento do vetor a cada entrada de item
    int contador2=1; //Variável que estabelece a criação da primeira posição do vetor
    for(j=0;j<12;j++){
        for(z=0;z<20;z++){
            if(q[j]==r[z] && contador2==1){ //Condição para a primeira posição
                w = (int *) realloc(w,contador*sizeof(int));
                w[contador-1]=q[j];
                contador2++; //Para que essa condição não seja repetida durante a execução
                contador++; //Para continuar aumentando o tamanho do vetor se preciso
            }
            else if(q[j]==r[z]){ //Condição realizada da segunda vez em diante durante a execução do programa
                for(k=0;k<contador-1;k++){  //A relação de exibição e contador é de +2, então, se o contador estiver em 7, significa que o vetor tem 5 posições ocupadas ou que podem ser ocupadas
                    if(q[j]!=w[k]){
                        validade++; //Verifica se determinado número já está contido no vetor que está sendo alterado
                    }
                }
                if(validade==contador-1){ //Condição acessada se o número q[j] não estiver no vetor principal
                    w = (int *) realloc(w,contador*sizeof(int)); //Adição de mais um tamanho
                    w[contador-1]=q[j]; //Recepção na posição
                    contador++;
                    validade=0; //Zerar é importante para que seja aferido para outro número q[j] se este já está alocado
                }
                else
                    validade=0; //Zerar é importante para que seja aferido para outro número q[j] se este já está alocado
            }
        }
    }
    *tamanho = contador-1; //Receptor, variavel da função main receberá a alteração de tamanho
}
