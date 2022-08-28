//Gabriel Siqueira Silva - 20203008814
//Cria 6 arquivos, 2 para cada exerc�cio. O programa tem por objetivo estipular o tamanho em bytes de cada um dos arquivos e comparar o tamanho ocupado por um arquivo edit�vel no bloco de notas e um arquivo bin�rio.
/*
L�gica - Os n�meros s�o rand�micos, por tanto, RAND_MAX deve ser estabelecido, no gcc 8.3.0, o valor vai at� 32767 dessa forma � necess�rio que o valor seja trabalhado atrav�s de opera��es de soma e multiplica��o, j� no gcc 9.3.0 o valor m�ximo � 2147483647, n�o necessitando fazer nenhuma manipula��o para esse exerc�cio. Para o c�lculo de bytes utiliza-se duas fun��es: fseek() e ftell(), a primeira define a atual posi��o de leitura do arquivo, assim, fseek(ponteiro, 0, SEEK_END) define como posi��o o END OF FILE, o final do arquivo, dessa forma com ftell(), transforma essa informa��o em retorno, no qual esse � o tamanho em bytes da atual posi��o de leitura, o fim, que compreende o arquivo inteiro.

Nota: Nos arquivos textos, foram armazenados apenas n�meros, sem espa�os entre eles.

Explica��o dos arquivos - O tamanho de um arquivo texto � definido pela quantidade de caracteres presentes nele, ou seja, no primeiro exerc�cio, quando armazenamos 100 n�meros de valores n�o negativos menores que 10, isso significa que estamos armazenando 1 byte a cada 1 n�mero armazenado, portanto o n�mero 9 tem 1 byte, 8 tem 1 byte tamb�m, juntando todos temos 100 bytes, isso acontece pois o n�mero, quando armazenado em arquivo texto tem a convers�o a partir da tabela ASCII, essa tabela converte o n�mero em quest�o em n�mero bin�rio que ocupa 8 bits (1 byte). Diferentemente do arquivo bin�rio, sua armazenagem � de acordo com o tipo do item armazenado, se o item for um inteiro, ent�o ele gastar� 4 bytes para realizar o armazenamento ent�o para 100, 400 bytes. A vantagem � que mesmo que aumente o tamanho do n�mero, o tamanho de um arquivo bin�rio se preserva.

Por exemplo, int x=50000, um arquivo texto gastar� 5 bytes, enquanto um arquivo bin�rio utilizar� de 2 ou 4 bytes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){

    FILE *texto;
    FILE *binario;
    int i,v[100]; //Contador para repeti��o e o vetor com os itens aleat�rios
    long int tamText, tamBin; //Vari�veis que receber�o ftell() que define o tamanho do arquivo na sua atual posi��o
    int verificarGravacao; //Analisa as grava��es em arquivos bin�rios j� que estes s�o complicados de serem lidos
    // Quest�o 1
    texto = fopen("textoAtividade1.txt","w");
    binario = fopen("binarioAtividade1.txt","wb"); //.txt n�o define se o arquivo � texto
    if (texto == NULL || binario == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    printf("Atividade 1 - Entre 0 e 9:\n");
    srand(time(NULL));
    for (i=0; i<100; i++){
        v[i]=rand()%10; //Valores rand�micos de 0 a 9
        fprintf(texto, "%d",v[i]); //Armazenagem no arquivo texto
    }
    verificarGravacao = fwrite(v,sizeof(int),100,binario); //Armazenagem no arquivo bin�rio
    if(verificarGravacao != 100){
        printf("Erro na escrita do arquivo!\n");
        exit(1);
    }
    fseek(texto, 0, SEEK_END); //Define a posi��o do arquivo dado um n�mero de bytes que devem ser deslocados (0) juntamente da origem que ser� determinada por SEEK.
    //Como a posi��o de origem � o fim do arquivo, estipula-se 0 de deslocamento pois n�o ter� mais nenhuma informa��o al�m do fim do arquivo, dessa forma consegue-se a posi��o que desejamos
    fseek(binario, 0, SEEK_END);

    tamText = ftell(texto); //Retorna a posi��o atual no arquivo. Como o fseek determinou o fim do arquivo, a posi��o, dada em bytes ser� a quantidade de bytes do arquivo por inteiro
    tamBin = ftell(binario);

    fclose(texto); //Salva e fecha o arquivo
    fclose(binario);
    printf("O tamanho total de textoAtividade1.txt = %ld bytes e o tamanho de binarioAtividade1.txt = %ld bytes. ",tamText,tamBin);
    printf("Arquivos gerados!\n");
    // Quest�o 2
    printf("Atividade 2 - Entre 1000 e 9999:\n");
    texto = fopen("textoAtividade2.txt","w");
    binario = fopen("binarioAtividade2.txt","wb");
    if (texto == NULL || binario == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    srand(time(NULL));
    for (i=0; i<100; i++){
        v[i]=1000+(rand()%9000); //O valor randomizado entre 1000 e 9999. O 1000+ limita a fun��o rand, assim ela n�o iniciar� do 0
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
    // Quest�o 3
    printf("Atividade 3 - Entre 10000 e 99999:\n");
    texto = fopen("textoAtividade3.txt","w");
    binario = fopen("binarioAtividade3.txt","wb");
    if (texto == NULL || binario == NULL){ //Caso n�o abra o arquivo
        printf("Problema com a abertura do arquivo!\n");
        exit(1); //Aborta o programa
    }
    srand(time(NULL));
    for (i=0; i<100; i++){
        //v[i]=10000+(2*rand()+rand()%24466); //Opera��o realizada no gcc 8.3.0, no windows. O valor randomizado entre 10000 e 99999. O 10000+ limita a fun��o rand, assim ela n�o iniciar� do 0. Como rand() pode ir de 0 � 32767 e dentro do par�nteses n�s desejamos o valor 89999, rand() pode ser multiplicado por 2, assumindo o valor m�ximo de 65534 + um rand() limitado � 24465, dessa forma o valor m�ximo dessa opera��o � 99999 e o m�nimo � 10000
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
