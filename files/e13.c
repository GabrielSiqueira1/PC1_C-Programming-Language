//Gabriel Siqueira Silva - 20203008814
//Cria 6 arquivos, 2 para cada exercício. O programa tem por objetivo estipular o tamanho em bytes de cada um dos arquivos e comparar o tamanho ocupado por um arquivo editável no bloco de notas e um arquivo binário.
/*
Lógica - Os números são randômicos, por tanto, RAND_MAX deve ser estabelecido, no gcc 8.3.0, o valor vai até 32767 dessa forma é necessário que o valor seja trabalhado através de operações de soma e multiplicação, já no gcc 9.3.0 o valor máximo é 2147483647, não necessitando fazer nenhuma manipulação para esse exercício. Para o cálculo de bytes utiliza-se duas funções: fseek() e ftell(), a primeira define a atual posição de leitura do arquivo, assim, fseek(ponteiro, 0, SEEK_END) define como posição o END OF FILE, o final do arquivo, dessa forma com ftell(), transforma essa informação em retorno, no qual esse é o tamanho em bytes da atual posição de leitura, o fim, que compreende o arquivo inteiro.

Nota: Nos arquivos textos, foram armazenados apenas números, sem espaços entre eles.

Explicação dos arquivos - O tamanho de um arquivo texto é definido pela quantidade de caracteres presentes nele, ou seja, no primeiro exercício, quando armazenamos 100 números de valores não negativos menores que 10, isso significa que estamos armazenando 1 byte a cada 1 número armazenado, portanto o número 9 tem 1 byte, 8 tem 1 byte também, juntando todos temos 100 bytes, isso acontece pois o número, quando armazenado em arquivo texto tem a conversão a partir da tabela ASCII, essa tabela converte o número em questão em número binário que ocupa 8 bits (1 byte). Diferentemente do arquivo binário, sua armazenagem é de acordo com o tipo do item armazenado, se o item for um inteiro, então ele gastará 4 bytes para realizar o armazenamento então para 100, 400 bytes. A vantagem é que mesmo que aumente o tamanho do número, o tamanho de um arquivo binário se preserva.

Por exemplo, int x=50000, um arquivo texto gastará 5 bytes, enquanto um arquivo binário utilizará de 2 ou 4 bytes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    FILE *texto;
    FILE *binario;
    int i,v[100]; //Contador para repetição e o vetor com os itens aleatórios
    long int tamText, tamBin; //Variáveis que receberão ftell() que define o tamanho do arquivo na sua atual posição
    int verificarGravacao; //Analisa as gravações em arquivos binários já que estes são complicados de serem lidos
    // Questão 1
    texto = fopen("textoAtividade1.txt","w");
    binario = fopen("binarioAtividade1.txt","wb"); //.txt não define se o arquivo é texto
    if (texto == NULL || binario == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    printf("Atividade 1 - Entre 0 e 9:\n");
    srand(time(NULL));
    for (i=0; i<100; i++){
        v[i]=rand()%10; //Valores randômicos de 0 a 9
        fprintf(texto, "%d",v[i]); //Armazenagem no arquivo texto
    }
    verificarGravacao = fwrite(v,sizeof(int),100,binario); //Armazenagem no arquivo binário
    if(verificarGravacao != 100){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    fseek(texto, 0, SEEK_END); //Define a posição do arquivo dado um número de bytes que devem ser deslocados (0) juntamente da origem que será determinada por SEEK.
    //Como a posição de origem é o fim do arquivo, estipula-se 0 de deslocamento pois não terá mais nenhuma informação além do fim do arquivo, dessa forma consegue-se a posição que desejamos
    fseek(binario, 0, SEEK_END);

    tamText = ftell(texto); //Retorna a posição atual no arquivo. Como o fseek determinou o fim do arquivo, a posição, dada em bytes será a quantidade de bytes do arquivo por inteiro
    tamBin = ftell(binario);

    fclose(texto); //Salva e fecha o arquivo
    fclose(binario);
    printf("O tamanho total de textoAtividade1.txt = %ld bytes e o tamanho de binarioAtividade1.txt = %ld bytes. ",tamText,tamBin);
    printf("Arquivos gerados!\n");
    // Questão 2
    printf("Atividade 2 - Entre 1000 e 9999:\n");
    texto = fopen("textoAtividade2.txt","w");
    binario = fopen("binarioAtividade2.txt","wb");
    if (texto == NULL || binario == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    srand(time(NULL));
    for (i=0; i<100; i++){
        v[i]=1000+(rand()%9000); //O valor randomizado entre 1000 e 9999. O 1000+ limita a função rand, assim ela não iniciará do 0
        fprintf(texto, "%d",v[i]);
    }
    verificarGravacao = fwrite(v,sizeof(int),100,binario);
    if(verificarGravacao != 100){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    fseek(texto, 0, SEEK_END);
    fseek(binario, 0, SEEK_END);

    tamText = ftell(texto);
    tamBin = ftell(binario);

    fclose(texto);
    fclose(binario);
    printf("O tamanho total de textoAtividade2.txt = %ld bytes e o tamanho de binarioAtividade2.txt = %ld bytes. ",tamText,tamBin);
    printf("Arquivos gerados!\n");
    // Questão 3
    printf("Atividade 3 - Entre 10000 e 99999:\n");
    texto = fopen("textoAtividade3.txt","w");
    binario = fopen("binarioAtividade3.txt","wb");
    if (texto == NULL || binario == NULL){ //Caso não abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    srand(time(NULL));
    for (i=0; i<100; i++){
        //v[i]=10000+(2*rand()+rand()%24466); //Operação realizada no gcc 8.3.0, no windows. O valor randomizado entre 10000 e 99999. O 10000+ limita a função rand, assim ela não iniciará do 0. Como rand() pode ir de 0 à 32767 e dentro do parênteses nós desejamos o valor 89999, rand() pode ser multiplicado por 2, assumindo o valor máximo de 65534 + um rand() limitado à 24465, dessa forma o valor máximo dessa operação é 99999 e o mínimo é 10000
        v[i]=10000+(rand()%90000); //Rand no Linux/Ubuntu
        fprintf(texto, "%d",v[i]);
    }
    verificarGravacao = fwrite(v,sizeof(int),100,binario);
    if(verificarGravacao != 100){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    fseek(texto, 0, SEEK_END);
    fseek(binario, 0, SEEK_END);

    tamText = ftell(texto);
    tamBin = ftell(binario);

    fclose(texto);
    fclose(binario);
    printf("O tamanho total de textoAtividade3.txt = %ld bytes e o tamanho de binarioAtividade3.txt = %ld bytes. ",tamText,tamBin);
    printf("Arquivos gerados!\n");
    return 0;
}
