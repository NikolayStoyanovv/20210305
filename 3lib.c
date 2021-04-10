 #include<stdio.h>
 #include<stdlib.h>
 #include"3.h"
 typedef struct Temperature{
    float tempHijaVihren;
    float tempVryhVihren;
}t_temperature1;
 void tempereture(){
     int choice;
    t_temperature1 *temp = (t_temperature1 *)malloc(sizeof(t_temperature1));
    printf("Press 1 if you know the temperature of hijaVihren\n "
    "or press 2 if you know the temerature of vryhVihren\n");
    scanf("%d",&choice);
     switch(choice){
            case 1:
                printf("Please enter the temperature of hijaVihren\n");
                scanf("%f", &temp->tempHijaVihren);
                fflush(stdin);
                temp->tempVryhVihren=temp->tempHijaVihren+(968/100*0.5);
                printf("The temperature of vryhVihren:%f\n",temp->tempVryhVihren);
            
            break;
            case 2:
                printf("Please enter the temperature of hijaVihren\n");
                scanf("%f", &temp->tempVryhVihren);
                fflush(stdin);
                temp->tempHijaVihren=temp->tempVryhVihren-(968/100*0.5);
                 printf("The temperature of vryhVihren:%f\n",temp->tempHijaVihren);
        
            break;
 
     }
 }
 