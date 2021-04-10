/*Задача 2 Пощенските такси на дадена куриерска фирма се определят според
тежестта на пратките (с точност до цял грам) и обема, както е показано в таблицата.
Тегло (с точност до 1 грам) Такса до 20 г 0,46 лева; 21-50 г 0,69 лева; 51-100 г
1,02 лева; 101-200 г 1,75 лева; 201-350 г 2,13 лева; 351-500 г 2,44 лева; 501-
1000 г 3,20 лева; 1001-2000 г 4,27 лева; 2001-3000 г 5,03 лева;


Обем: до 10см + 0,01лв; 10- 50 см + 0,11 лева, 50-100 см + 0,22лв, 100-150см + 0,33лв, 150-
250см +0,56лв, 250-400см+1.50лв, 400-500см+3,11лв, 500-600см+4,89лв, над 600см+ 5.79лв
Потребителя се пита за броя на пратките пратки след което теглото на всяка пратка и обема и.
Определете според пощенските такси в тази куриерска фирма как по-евтино да изпрати своите
пратки като една или да ги изпрати като отделни пратки.
Изход 1:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В
този случай изпращането ще струва ... лева.
Изход 2:
За пратки с тегло ... грама обем ... и ... грама ...обем е по-добре да бъдат изпратени заедно. В
този случай изпращането ще струва ... лева.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct package
{
    float weight;
    float volume;
} t_package;
 


float Pratki(t_package *price,float*p,float *p1){
   
int weight[9]={20,50,100,200,350,500,1000,2000,3000};
float weightPrize[9]={0.46,0.69,1.02,1.72,2.13,2.44,3.2,4.27,5.03};
int volume[9]={10,50,100,150,250,400,500,600,10000};
float volumePrize[9]={0.01,0.11,0.22,0.33,0.56,1.5,3.11,4.89,5.79};
for(int i=0;i<9;i++){
   
    if(price->weight<=weight[i]){
        price->weight=weightPrize[i];
        //printf("%.2f\n",price->weight);
        break;
    }
   
}for(int j=0;j<9;j++){
 if(price->volume<=volume[j]){
        price->volume=volumePrize[j];
        //printf("%.2f\n",price->volume);
        break;
    }
}
 float result=price->volume+price->weight;


 return result;
}
int main(){
    
    float sum=0.0;
    int count=0;
    float arr[count];
 
    float a=0,b;

    t_package *price = (t_package *)malloc(sizeof(t_package));
    
   
  printf("Please enter a number of packages");
  scanf("%d",&count);
  for(int k=0;k<count;k++){
        printf("Please enter a value of weight for package%d:\n",k+1);
        scanf("%f",&price->weight);
        fflush(stdin);
        float *p=&price->weight;
        fflush(stdin);
        printf("Please enter a value of volume for package:%d\n",k+1);
        scanf("%f",&price->volume);
        fflush(stdin);
        float *p1=&price->volume;
        fflush(stdin);
    
    //b=pratka(price,p2,p3);;
    a=Pratki(price,p,p1);
    arr[k]=a;
  }


 for(int r=0;r<count;r++){
     printf("%f\n",arr[r]);
     sum+=arr[r];
 }
 
 printf("\n%f",sum);
 
 
 
    return 0;
}

