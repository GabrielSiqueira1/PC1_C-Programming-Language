#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int mes,ano;
} TD;

typedef struct prod{
    int cod;
    float peso;
    TD valid;
} TPROD;

struct produtoLoja{
    char nome_do_produto[120];
    float preco;
    int qtd_estoque;
    TPROD adc;
};

float mediaPrecos(struct produtoLoja *dados, int tamanho){
    int z=0;
    float soma=0;
    for(z=0;z<tamanho;z++){
        soma=soma+dados[z].preco;
    }
    return soma/tamanho;
}

void organizacaoProd(struct produtoLoja *dados, int tamanho){
    int m=0,w=0,count;
    struct produtoLoja aux[tamanho];
    for (m=0;m<tamanho;m++){
        for (w=0;w<tamanho;w++){
            if(dados[m].adc.cod<dados[w].adc.cod){
                aux[m] = dados[m];
                dados[m] = dados[w];
                dados[w] = aux[m];
            }
            else if (dados[m].adc.cod == dados[w].adc.cod){
                if(dados[w].adc.valid.ano==dados[m].adc.valid.ano){
                    if(dados[w].adc.valid.mes>dados[m].adc.valid.mes){
                        aux[m] = dados[m];
                        dados[m] = dados[w];
                        dados[w] = aux[m];
                    }
                }
                else if(dados[w].adc.valid.ano!=dados[m].adc.valid.ano){
                    if(dados[w].adc.valid.ano>dados[m].adc.valid.ano){
                        aux[m] = dados[m];
                        dados[m] = dados[w];
                        dados[w] = aux[m];
                    }
                }
                else if(dados[w].adc.valid.mes==dados[m].adc.valid.mes && dados[w].adc.valid.ano==dados[m].adc.valid.ano){
                    if(dados[m].preco>dados[w].preco){
                        aux[m] = dados[m];
                        dados[m] = dados[w];
                        dados[w] = aux[m];
                    }
                }
            }
        }
    }
    for(count=0;count<tamanho;count++){
        printf("Nome: %s\n",dados[count].nome_do_produto);
        printf("Preco: %.2f\n",dados[count].preco);
        printf("Estoque: %d\n",dados[count].qtd_estoque);
        printf("Codigo: %d\n",dados[count].adc.cod);
        printf("Peso: %.2f\n",dados[count].adc.peso);
        printf("Validade: %d/%d\n",dados[count].adc.valid.mes,dados[count].adc.valid.ano);
    }
}

void precos(struct produtoLoja *dados, int tamanho){
    int j=0;
    int countMaior=0,countMenor=0;
    struct produtoLoja maior;
    struct produtoLoja menor;
    for(j=0;j<tamanho;j++){
        if(dados[j].preco>maior.preco || countMaior==0){
        maior=dados[j];
        countMaior++;
    }
        if(dados[j].preco<menor.preco || countMenor==0){
            menor=dados[j];
            countMenor++;
        }
    }
    printf("O produto com maior preco e %s, que custa %.2f e ha %d desses no estoque\n", maior.nome_do_produto,maior.preco, maior.qtd_estoque);
    printf("O produto com menor preco e %s, que custa %.2f e ha %d desses no estoque\n", menor.nome_do_produto,menor.preco, menor.qtd_estoque);
}

int main(){

    int tam=0,n,i=0;
    struct produtoLoja dados[10];
    do{
        printf("Digite o nome do produto: ");
        gets(dados[i].nome_do_produto);
        printf("Digite a quantidade em estoque: ");
        scanf("%d",&dados[i].qtd_estoque);
        printf("Digite o preco do produto: ");
        scanf("%f",&dados[i].preco);
        printf("Digite o codigo do produto: ");
        scanf("%d",&dados[i].adc.cod);
        printf("Digite o peso do produto: ");
        scanf("%f",&dados[i].adc.peso);
        printf("Digite o mes de validade do produto: ");
        scanf("%d",&dados[i].adc.valid.mes);
        printf("Digite o ano de validade do produto: ");
        scanf("%d",&dados[i].adc.valid.ano);
        printf("Deseja adicionar mais um produto: \n1. Sim \n2. Nao\n");
        scanf("%d",&n);
        getchar();
        if(n==1){
            i++;
            tam++;
        }
        else{
            i=10;
            tam++;
        }
    }while(i<10);
    for(i=0;i<tam;i++){
        printf("Nome: %s\n",dados[i].nome_do_produto);
        printf("Preco: %.2f\n",dados[i].preco);
        printf("Estoque: %d\n",dados[i].qtd_estoque);
        printf("Codigo: %d\n",dados[i].adc.cod);
        printf("Peso: %.2f\n",dados[i].adc.peso);
        printf("Validade: %d/%d\n",dados[i].adc.valid.mes,dados[i].adc.valid.ano);
    }
    organizacaoProd(dados,tam);
    system("PAUSE");
    return 0;
}
