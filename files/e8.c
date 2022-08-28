//Gabriel Siqueira Silva - 20203008814
//Realiza a contagem de palavras escolhidas pelo usuário num determinado arquivo
/*
Todos os exercícios são baseados em ponteiros que controlam o fluxo de informação de modo que neste caso, precisa-se que ler um arquivo já existente e verificar quantas vezes uma palavra apareceu. Note que, palavras derivadas não devem ser lidas como também as palavras compostas (hífen). Nesse programa, serão lidas palavras escolhidas pelo usuário e entre elas podem ter espaços ou qualquer tipo de pontuação.

Lógica - Para leitura fora utilizado o seguinte raciocínio: A palavra escolhida pelo usuário será levada a um loop, nesse loop a palavra escolhida é comparada a todas as strings do arquivo e essa repetição ocorre até o contador assumir o valor do tamanho da string menos um. Nesse mesmo loop uma variável irá contar quantos caracteres da palavra escolhida são iguais aos caracteres da palavra do arquivo, de forma linearizada, ou seja, palavra escolhida(posição 1) == palavra do arquivo(posição 1)... palavra escolhida(posição n) == palavra do arquivo(posição n).

Letras maiúsculas - Como são strings e caracteres pode ser usado a tabela ASCII, dessa forma, todas as formas de uma mesma letra são aceitas. Consequentemente em todas as comparações deve ser verificado se os caracteres são iguais a +32 ou -32 daquele mesmo caractere, por exemplo, doce e Doce são iguais pois d e D representa a mesma letra, mas como caractere eles serão iguais se D for somado com 32. 32 se deve a distância entre letras maiúsculas e minúsculas na tabela ASCII.

Pontuações - Deve ser analisado na palavra do arquivo se na posição que tem o mesmo valor do tamanho da palavra escolhida, se existe pontuação, caso exista, a palavra é a mesma, pois pontuações não podem ser consideradas na comparação, qualquer outra palavra diferença é descatada como igualdade, dessa forma "doce" e "doce," é a mesma palavra, diferentemente de "doce" e "doceiro".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *f; //Controla o fluxo de leitura e escrita de um arquivo, ponteiro do tipo FILE
    int count=0; //Contador inicializado; quantidade de vezes que a palavra aparece
    int i,count2; //Contadores de controle para repetição
    char nomeArquivo[100];
    char palavra[50];
    char palavrasArquivo[50];
    int tamString; //Recebe o tamanho das strings
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo,100,stdin);
    printf("Qual palavra voce busca? ");
    fgets(palavra,50,stdin);
    tamString = strlen(nomeArquivo); //Parte do código dedicada à retirada do \n gerado pelo fgets para que não ocorra um warning no prompt de comando
    if (nomeArquivo[tamString-1] == '\n'){
    	nomeArquivo[tamString-1] = '\0'; //Atualiza o final da string, retirando a quebra de linha
    }
    tamString = strlen(palavra);
    if (palavra[tamString-1] == '\n'){
    	palavra[tamString-1] = '\0';
    }
    f = fopen(nomeArquivo, "r"); //r - Read, abre o arquivo para leitura
    if (f == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    while(fscanf(f,"%s",palavrasArquivo)!=EOF){ //Realiza a leitura até o final do arquivo, End of File
        count2=0; //Inicialização
        for (i=0;i<strlen(palavra);i++){ //Realizar sem o strcmp permite que as palavras que sejam acompanhadas por ',','.',';', sejam analisadas da melhor forma, pois a palavra 'doce' é a mesma que 'doce,'.
            if(palavrasArquivo[i]==(palavra[i]-32) || palavrasArquivo[i]==(palavra[i]+32) || palavrasArquivo[i]==palavra[i]){ //A programação em C tem a capacidade de diferenciar letras maiúsculas e minúsculas, no entanto, não desejamos fazer isso, já que doce e Doce tem o mesmo sentido
                count2++;
            }
        }
        if(count2==strlen(palavra)){ //Para evitar palavras derivadas, por exemplo, doce e doceiro
            if (strlen(palavrasArquivo)>strlen(palavra)){
                if(palavrasArquivo[i]== ',' || palavrasArquivo[i]== '.' || palavrasArquivo[i]== ';')
                    count++; //Contador de igualdades
            }
            else
                count++;
        }
    }
    printf("A palavra %s aparece %d vezes no arquivo.\n",palavra,count);
    fclose(f); //Fecha o arquivo e garante que todos os dados foram salvos
    return 0;
}
