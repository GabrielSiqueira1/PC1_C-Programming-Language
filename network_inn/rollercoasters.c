#include <stdio.h>

int main(int  argc, char *argv[]){

	FILE *arq;
	arq = fopen(argv[1], "rt");

	if (arq == NULL){
     		printf("Problemas na abertura do arquivo\n");
     		return 0;
  	}

	char limit[100];
 	char *result;

	int happiness = 0;
	int counter = 0;
	int greater = 0;
	int maxHappiness = 0;

	while(!feof(arq)){
		result = fgets(limit, 100, arq);
		if(result){
			if(counter == 0){
				happiness+=10;
				counter+=1;
				greater = atoi(result);
			}else if(atoi(result) > greater){
				greater = atoi(result);
				happiness+=10;
			}else{
				greater = atoi(result);
				if(maxHappiness < happiness)
					maxHappiness = happiness;
				happiness = 10;
			}
		}
	}
	printf("%d\n", maxHappiness);
	fclose(arq);
	return 0;
}
