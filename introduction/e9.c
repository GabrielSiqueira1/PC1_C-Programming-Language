#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void fill(int *ptrv);
void sort(int *pptrv);
int bigthird(int *numbers);
int repeatedNumbers(int *numbers);
int ABSdifference(int *numbers);
int bigger(int *numbers);
int avarage(int *numbers);
int impairment (int *numbers);
int parity(int *numbers);

int main(){

    srand (time(0));
    int V [14];

    fill(V); //we pass the address of V[0], the first address

}

void fill(int *ptrv){

    int index,option;
    for (index=0;index<15;index++){
        ptrv[index]=rand()%100;
    }
    for (index=0;index<15;index++){
        printf("%2d\n",ptrv[index]);
    }
    do{
        printf("You have several options:\n");
        printf("1. Nothing;\n");
        printf("2. The number of even numbers in the vector;\n");
        printf("3. The sum of odd numbers in the vector;\n");
        printf("4. The number of numbers greater than the average of the vector;\n");
        printf("5. The highest value of vector;\n");
        printf("6. The highest difference in absolute value between consecutives elements of the vector;\n");
        printf("7. Ascending vector order;\n");
        printf("8. The third highest element in the vector;\n");
        printf("9. Eliminate repeated numbers in the vector;\n");
        printf("Choose a option:");
        scanf("%d",&option);
        if (option==2){
            printf("\n\n%d\n\n",parity(ptrv));
        }
        else if (option==3){
            printf("\n\n%d\n\n",impairment(ptrv));
        }
        else if (option==4){
            printf("\n\n%d\n\n",avarage(ptrv));
        }
        else if (option==5){
            printf("\n\n%d\n\n",bigger(ptrv));
        }
        else if (option==6){
            printf("\n\n%d\n\n",ABSdifference(ptrv));
        }
        else if (option==8){
            printf("\n\n%d\n\n",bigthird(ptrv));
        }
        else if (option==7){
            sort (ptrv);
        }
        else if (option==9){
            repeatedNumbers (ptrv);
        }
    }
    while(option!=1);
}

void sort(int *pptrv){
    int index,index2,aux;

    for (index=0;index<15;index++){
        for (index2=0;index2<15;index2++){
            if (pptrv[index]<pptrv[index2]){
                aux=pptrv[index];
                pptrv[index]=pptrv[index2];
                pptrv[index2]=aux;
            }
        }
    }
    for (index=0;index<15;index++){
        printf("%2d\n",pptrv[index]);
    }
}

int bigthird (int *numbers){
    int index, bigger=0,count=0;
    for (index=0;index<15;index++){
        if (index==0 || numbers[index]>=bigger){
            bigger=numbers[index];
            count++;
            if(count==3){
                return bigger;
            }
        }
    }
}

int repeatedNumbers(int *numbers){
    int index,index2;
    for (index=0;index<15;index++){
        for (index2=0;index2<15;index2++){
            if (numbers[index]==numbers[index2] && index!=index2){
                numbers[index]=rand()%100;
            }
        }
    }
    for (index=0;index<15;index++){
        printf("%2d\n",numbers[index]);
    }
}

int ABSdifference(int *numbers){
    int index,difference;
    for (index=0;index<15;index++){
        if(index<14){
            if (index==0 || (abs(numbers[index+1]-numbers[index]))>difference){
                difference=abs(numbers[index+1]-numbers[index]);
            }
        }
    }
    return difference;
}

int bigger (int *numbers){
    int index, bigger=0;
    for (index=0;index<15;index++){
        if (index==0 || numbers[index]>=bigger){
            bigger=numbers[index];
        }
    }
    return bigger;
}

int avarage (int *numbers){
    int sum=0,index,count=0;
    float avarage;
    for (index=0;index<15;index++){
        sum=sum+numbers[index];
    }
    avarage=sum/15.0;
    for (index=0;index<15;index++){
        if(numbers[index]>avarage){
            count++;
        }
    }
    return count;
}

int impairment (int *numbers){
    int sum=0,index;
    for (index=0;index<15;index++){
        if(numbers[index]%2!=0){
            sum=sum+numbers[index];
        }
    }
    return sum;
}

int parity (int *numbers){
    int count=0,index;
    for (index=0;index<15;index++){
        if(numbers[index]%2==0){
            count++;
        }
    }
    return count;
}
