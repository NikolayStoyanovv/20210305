/*Задача 1. За да направи една етажерка, дърводелец се нуждае от следните
компоненти: 4 дълги дъски, 6 къси дъски, 12 малки скоби, 2 големи скоби и 14 винта.
Дърводелецът има на склад А дълги дъски, В къси дъски, С малки скоби, D големи скоби и E
винта. Колко етажерки може да направи дърводелецът?
Изход:
С наличните на склад материали (33 дълги дъски, 55 къси дъски, 88 малки скоби, 22 големи
скоби и 99 винта) дърводелецът може да направи 7 етажерки.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DDYSKI 4
#define KDYSKI 6
#define MSKOBA 12
#define GSKOBA 2
#define VINTOVE 14

typedef struct etazherka
{
    int kysa_dyska;
    int dylga_dyska;
    int malka_skoba;
    int golqma_skoba;
    int vint;
} t_etazherka;

int main()
{
    t_etazherka *nalichni = (t_etazherka *)malloc(sizeof(t_etazherka));
    printf("Please enter a value of long planks:\n");
    scanf("%d", &nalichni->dylga_dyska);
    fflush(stdin);
    printf("Please enter a value of short planks:\n");
    scanf("%d", &nalichni->kysa_dyska);
    fflush(stdin);
    printf("Please enter a value of small clamps:\n");
    scanf("%d", &nalichni->malka_skoba);
    fflush(stdin);
    printf("Please enter a value of big clamps:\n");
    scanf("%d", &nalichni->golqma_skoba);
    fflush(stdin);
    printf("Please enter a value of screws:\n");
    scanf("%d", &nalichni->vint);
    
    int count[5];
    count[0] = nalichni->dylga_dyska / DDYSKI;
    count[1] = nalichni->kysa_dyska / KDYSKI;
    count[2] = nalichni->malka_skoba/ MSKOBA;
    count[3] = nalichni->golqma_skoba / GSKOBA;
    count[4] = nalichni->vint/ VINTOVE;
    int result = count[0];
    for (int i = 0; i < 5; i++)
    {
        if (result > count[i])
        {
            result = count[i];
        }
    }
    printf("With the materials in store (%d-long planks, %d -short planks, %d-small clamps,\n"
           "%d- big clamps, %d-screws)can be produced %d etazherki:\n ",
           nalichni->dylga_dyska, nalichni->kysa_dyska,
           nalichni->malka_skoba, nalichni->golqma_skoba, nalichni->vint, result);
    return 0;
}