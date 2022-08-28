//Gabriel Siqueira Silva - 20203008814
//Realiza a contagem de palavras escolhidas pelo usuário num determinado arquivo e através dessa contagem é estabelecido quantas palavras devem ser dispensadas do arquivo

/*
Utilizando a explicação do exercício anterior, neste devemos apenas realizar o processo inverso, ou seja, todas as palavras que não tenham o contador da igualdade linear, estabelecido por palavra escolhida(posição 1) == palavra do arquivo(posição 1)... palavra escolhida(posição n) == palavra do arquivo(posição n), igual ao tamanho da palavra escolhida, dessa forma, doce e dado resultará num contador = 1 não igual a 4.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE *f; //Controla o fluxo de leitura e escrita de um arquivo, ponteiro do tipo FILE, leitura
    FILE *q; //Controla o fluxo de leitura e escrita de um arquivo, ponteiro do tipo FILE, escrita
    int count=0; //Contador inicializado, um auxílio
    int i,count2; //Contadores de controle para repetição
    int controller=0;
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
    q = fopen("resultado.txt","w"); //w - Write, cria e escreve num arquivo
    if (f == NULL || q == NULL){ //Caso não abra o arquivo
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
                if(palavrasArquivo[i]== ',' || palavrasArquivo[i]== '.' || palavrasArquivo[i]== ';'){
                    count++; //Contador de igualdades
                    fputc(palavrasArquivo[i],q); //Insere ',','.',';'
                }
            }
            else
                count++;
        }
        else{ //Todas as palavras que não se enquadram na palavra inserida no prompt de comando
            if(controller==0){ //Evita espaço branco na retirada da palavra, ou seja, a frase é empurrada para a esquerda
                fputs(palavrasArquivo,q); //Insere a palavra no documento q
                controller++;
            }
            else{
                fputc(' ',q); //Insere um espaço a cada palavra
                fputs(palavrasArquivo,q); //Insere a palavra no documento q
            }
        }
    }
    //printf("A palavra %s aparece %d vezes no arquivo.\n",palavra,count);
    printf("Arquivo resultado.txt foi gerado.\n");
    fclose(f); //Fecha o arquivo e garante que todos os dados foram salvos
    return 0;
}
