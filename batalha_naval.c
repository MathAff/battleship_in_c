#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

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
    for (int x = 0; x<=10; x++){
        if (x!=0){
            if (x<10) {
                printf("0%d ", x);    
            } else {
                printf("%d ", x);
            }
            //printf ("%c ", toupper(getRowChar(x)));
        } else {
            printf (" #");
        }

        for (int y = 0; y <10; y++) {
            if (x!=0) {

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
                if (y+1<10) {
                    printf("    0%d", y+1);    
                } else {
                    printf("   %d ", y+1);
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
    for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
            field[x][y] = 0;
        }
    }
}

void debugField (int field[10][10]) {
    for (int y=0; y<10; y++) {
        for (int x=0; x<10; x++) {
            printf("%d, ", field[x][y]);
        }
        printf("\n");
    }
}

int isPlaceable() {
    return 1;
}

void main () {
    char choice;
    int playerField [10][10];
    int botField [10][10];
    
    initField(playerField);
    initField(botField);

    system("clear");

    //puts("=== Welcome to Battleship ===");
//
    //puts("\nIn this game you and your opponent have to place some ships in the ocean, they're:");
    //puts("\n\t|  qt  |      type     |  size  |");
    //puts("\n\t|  05  |   destroyers  |   02   |");
    //puts("\t|  04  |   submarines  |   03   |");
    //puts("\t|  03  |     cruiser   |   03   |");
    //puts("\t|  02  |   battleship  |   04   |");
    //puts("\t|  01  |     carrier   |   05   |");

    //printf("\n\nStart game? (Y/N) ");
    //scanf("%c", &choice);
    //choice = tolower(choice);

    //while (choice == 'y') {
        int line;
        int column;
        int shipsPlaced = 0;

        //system("clear");
    //
        //puts("Guess where your enemy's ships are. Choose wisely");
        //puts("The game has begun");
//
        //sleep(5);
        
        while (shipsPlaced < 5){
            system("clear");

            debugField(playerField);
            drawField(playerField);
            puts("Choose the line (A - J): ");
            scanf("%d", &line);
            line=line-1;
    
            puts ("Choose the column (01 - 10): ");
            scanf("%d", &column);
            column= column -1;

            if (isPlaceable() == 1) {
                playerField [line][column] = 2;
            }
        }

        choice = 'n';
//    }
    //debugField(playerField);
    //debugField(botField);
}