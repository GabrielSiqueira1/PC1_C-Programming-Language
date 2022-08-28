//Gabriel Siqueira Silva - 20203008814
//Realiza a contagem de palavras escolhidas pelo usu�rio num determinado arquivo
/*
Todos os exerc�cios s�o baseados em ponteiros que controlam o fluxo de informa��o de modo que neste caso, precisa-se que ler um arquivo j� existente e verificar quantas vezes uma palavra apareceu. Note que, palavras derivadas n�o devem ser lidas como tamb�m as palavras compostas (h�fen). Nesse programa, ser�o lidas palavras escolhidas pelo usu�rio e entre elas podem ter espa�os ou qualquer tipo de pontua��o.

L�gica - Para leitura fora utilizado o seguinte racioc�nio: A palavra escolhida pelo usu�rio ser� levada a um loop, nesse loop a palavra escolhida � comparada a todas as strings do arquivo e essa repeti��o ocorre at� o contador assumir o valor do tamanho da string menos um. Nesse mesmo loop uma vari�vel ir� contar quantos caracteres da palavra escolhida s�o iguais aos caracteres da palavra do arquivo, de forma linearizada, ou seja, palavra escolhida(posi��o 1) == palavra do arquivo(posi��o 1)... palavra escolhida(posi��o n) == palavra do arquivo(posi��o n).

Letras mai�sculas - Como s�o strings e caracteres pode ser usado a tabela ASCII, dessa forma, todas as formas de uma mesma letra s�o aceitas. Consequentemente em todas as compara��es deve ser verificado se os caracteres s�o iguais a +32 ou -32 daquele mesmo caractere, por exemplo, doce e Doce s�o iguais pois d e D representa a mesma letra, mas como caractere eles ser�o iguais se D for somado com 32. 32 se deve a dist�ncia entre letras mai�sculas e min�sculas na tabela ASCII.

Pontua��es - Deve ser analisado na palavra do arquivo se na posi��o que tem o mesmo valor do tamanho da palavra escolhida, se existe pontua��o, caso exista, a palavra � a mesma, pois pontua��es n�o podem ser consideradas na compara��o, qualquer outra palavra diferen�a � descatada como igualdade, dessa forma "doce" e "doce," � a mesma palavra, diferentemente de "doce" e "doceiro".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *f; //Controla o fluxo de leitura e escrita de um arquivo, ponteiro do tipo FILE
    int count=0; //Contador inicializado; quantidade de vezes que a palavra aparece
    int i,count2; //Contadores de controle para repeti��o
    char nomeArquivo[100];
    char palavra[50];
    char palavrasArquivo[50];
    int tamString; //Recebe o tamanho das strings
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo,100,stdin);
    printf("Qual palavra voce busca? ");
    fgets(palavra,50,stdin);
    tamString = strlen(nomeArquivo); //Parte do c�digo dedicada � retirada do \n gerado pelo fgets para que n�o ocorra um warning no prompt de comando
    if (nomeArquivo[tamString-1] == '\n'){
    	nomeArquivo[tamString-1] = '\0'; //Atualiza o final da string, retirando a quebra de linha
    }
    tamString = strlen(palavra);
    if (palavra[tamString-1] == '\n'){
    	palavra[tamString-1] = '\0';
    }
    f = fopen(nomeArquivo, "r"); //r - Read, abre o arquivo para leitura
    if (f == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    while(fscanf(f,"%s",palavrasArquivo)!=EOF){ //Realiza a leitura at� o final do arquivo, End of File
        count2=0; //Inicializa��o
        for (i=0;i<strlen(palavra);i++){ //Realizar sem o strcmp permite que as palavras que sejam acompanhadas por ',','.',';', sejam analisadas da melhor forma, pois a palavra 'doce' � a mesma que 'doce,'.
            if(palavrasArquivo[i]==(palavra[i]-32) || palavrasArquivo[i]==(palavra[i]+32) || palavrasArquivo[i]==palavra[i]){ //A programa��o em C tem a capacidade de diferenciar letras mai�sculas e min�sculas, no entanto, n�o desejamos fazer isso, j� que doce e Doce tem o mesmo sentido
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
