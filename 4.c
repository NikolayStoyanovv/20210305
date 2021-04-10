/*  Да се състави програма, с помощта на която 2
 (3, 1) играчи могат да играят (с право на връщане на
 ходовете) следната игра ЛАБИРИНТ: Трябва да се достигне
 до финала, отбелязан с F. Числото във всяка клетка
 показва броя стъпки по права линия, които могат да са
 направят при следващия ход. Като се започне от горния
 ляв ъгъл, са възможни само два хода
 
    3324312
 2423243
 4232421
 4412234
 3233422
 3242321
 113342F
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
    int row;
    int col;
}field;

char table[7][7] =
     {
         {"3324312"},
         {"2423243"},
         {"4232421"},
         {"4412234"},
         {"3233422"},
         {"3242321"},
         {"113342F"},
     };

void printTable();
int getNumericValue(field f);
int isEndOfGame(field current);
int isValidMove(field next);

int main(){
     int stackSize;
     printf("Choose difficulty:\n");
     printf("Beginner (50 moves) type 50\n");
     printf("Amateur (40 moves) type 40\n");
     printf("Semi-Pro (30 moves) type 30\n");
     printf("Pro (20 moves) type 20\n");
     printf("World class (10 moves) type 10\n");
     printf("Legandary (5 moves) type 5\n");
     scanf("%d",&stackSize);
     fflush(stdin);
     field* movesStack = malloc(sizeof(field)*(stackSize+1));
     int index = 0;
     field current = {0,0};
     field next = {0,0};
     movesStack[index] = current;
     int direction;
     while (isEndOfGame(current))
     {
        printTable();
        printf("your current position is at %d %d value(%d)\n",current.row,current.col,getNumericValue(current));
        printf("%d left moves\n",stackSize - index);
        printf("choose direction\nright(1)\nleft(2)\nup(3)\ndown(4)\nturn back one move(5)\n");
        scanf("\n%d",&direction);
        switch(direction){
            case 1:
            next.col = current.col+getNumericValue(current);
            next.row = current.row;
            break;

            case 2:
            next.col = current.col-getNumericValue(current);
            next.row = current.row;
            break;

            case 3:
            next.col = current.col;
            next.row = current.row - getNumericValue(current);
            break;

            case 4:
            next.col = current.col;
            next.row = current.row + getNumericValue(current);
            break;

            case 5:
            if (index>0)
            {
                index--;
                current.row = movesStack[index].row;
                current.col = movesStack[index].col;
                continue;
            }

            else{
                printf("there are no past moves!!!\n");
                continue;
            }
            
            break;
        }
        if (isValidMove(next))
        {
            ++index;
            movesStack [index] = next;
            current = next;
        }
        else{
            printf("Invalid move!!!\n");
            printf("Try another one!!!\n");
        }
        if (index == stackSize)
        {
            printf("too many moves game is over!!!\n");
            free(movesStack);
            return 0;
        }
        
     }
     printf("You won the game!!");
     free(movesStack);
     return 0;
}

void printTable(){
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%c",table[i][j]);
        }
        printf("\n");
    }
}
int getNumericValue(field f){
    return table[f.row][f.col] - '0';
}

int isValidMove(field next){
    if (next.row<=7 && next.row>=0)
    {
        if (next.col<=7 && next.col>=0)
        {
            return 1;
        }
    }
    return 0;
}

int isEndOfGame(field current){
    if (table[current.row][current.col] == 'F')
    {
        return 0;
    }
    return 1;
}