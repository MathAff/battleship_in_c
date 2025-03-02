#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char getRowChar (int rowInt) {
    switch (rowInt)
    {
    case 1:
        return 'a';
        break;

    case 2:
        return 'b';
        break;

    case 3:
        return 'c';
        break;

    case 4:
        return 'd';
        break;

    case 5:
        return 'e';
        break;

    case 6:
        return 'f';
        break;

    case 7:
        return 'g';
        break;

    case 8:
        return 'h';
        break;
        
    case 9:
        return 'i';
        break;

    case 10:
        return 'j';
        break;
    default:
        break;
    }
}

int getRowInt (char rowLetter) {
    switch (rowLetter)
    {
    case 'a':
        return 0;
        break;

    case 'b':
        return 1;
        break;

    case 'c':
        return 2;
        break;

    case 'd':
        return 3;
        break;

    case 'e':
        return 4;
        break;

    case 'f':
        return 5;
        break;

    case 'g':
        return 6;
        break;

    case 'h':
        return 7;
        break;

    case 'i':
        return 8;
        break;

    case 'j':
        return 9;
        break;

    default:
        break;
    }
}


void drawField(int field [10][10]) {
    for (int y = 0; y<=10; y++){
        if (y!=0){
            if (y<10) {
                printf("0%d ", y);    
            } else {
                printf("%d ", y);
            }
            //printf ("%c ", toupper(getRowChar(y)));
        } else {
            printf (" #");
        }

        for (int x = 0; x <10; x++) {
            if (y!=0) {

                switch (field[x][y])
                {
                case 0:
                    printf("  [~] ");
                    break;
                
                case 1:
                    printf("  [*] ");
                    break;

                case 2:
                    printf("  [#] ");

                default:
                    printf("  [~] ");
                    break;
                }
            } else {
                if (x+1<10) {
                    printf("    0%d", x+1);    
                } else {
                    printf("   %d ", x+1);
                }
            }
        }
        
        printf("\n");
    }
}

int fillBotField (int botField[10][10]) {
    return 0;
}

void initField (int field [10][10]) {
    for (int y=0; y<10; y++) {
        for (int x=0; x<10; x++) {
            field[x][y] = 0;
        }
    }
}

void debugField (int field[10][10]) {
    for (int y=0; y<10; y++) {
        for (int x=0; x<10; x++) {
            printf("%d, ", field[x][y]);
        }
    }
}


void main () {
    int playerField [10][10];
    int botField [10][10];

    initField(playerField);
    initField(botField);
    //1 porta-aviões (cinco quadrados), 2 navios-tanque (quatro quadrados), 3 contratorpedeiros (três quadrados) e 4 submarinos (dois quadrados)[1].

    float awnser;
    //printf("Bem vindo ao Batalha naval");
    //printf("\n\t2 Fragatas\n");
    system("clear");
    drawField(playerField);

    //debugField(playerField);
    //debugField(botField);
}