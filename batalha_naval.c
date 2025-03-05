#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

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

char *getShipName (char ship) {
    switch (ship)
    {
    case 'd':
        return "destroyier";
        break;
    case 's':
        return "submarine";
        break;
    case 'r':
        return "cruiser";
        break;
    case 'b':
        return "battleship";
        break;
    case 'a':
        return "carrier";
        break;
    default:
        break;
    }
}


void drawField(int field [10][10]) {
    for (int x = 0; x<=10; x++){
        if (x!=0){
            // if (x<10) {
            //     printf("0%d ", x);    
            // } else {
            //     printf("%d ", x);
            // }
            printf ("%c ", toupper(getRowChar(x)));
        } else {
            printf ("#");
        }

        for (int y = 0; y <10; y++) {
            if (x!=0) {

                switch (field[x-1][y])
                {
                case 0:
                    printf("  [~] ");
                    break;
                
                case 1:
                    printf("  [*] ");
                    break;

                case 2:
                    printf("  [#] ");
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

void drawBothField (int userField [10][10], int botField [10][10]) {
    int newX=0, newY=0;

    printf ("                          PLAYER FIELD                          |                          ENEMY FIELD\n");

    for (int x = 0; x<=10; x++){
        if (x!=0){
            printf ("%c ", toupper(getRowChar(x)));
        } else {
            printf ("#");
        }

        for (int y = 0; y <= 20; y++) {
            if (x!=0) {
                if (y < 10) {
                    switch (userField[x-1][y])
                    {
                    case 0:
                        printf("  [~] ");
                        break;
                    
                    case 1:
                        printf("  [*] ");
                        break;
    
                    case 2:
                        printf("  [#] ");
                        break;
                    }
                } else if (y == 10) {
                    if (x == 0) {
                        printf("  |  #");
                    } else {
                        printf("  |  %c ", getRowChar(x));
                    }
                                        
                } else {
                    switch (botField[x-2][y-1])
                    {
                    case 0:
                        printf("  [~] ");
                        break;
                    
                    case 2:
                        printf("  [#] ");
                        break;
                    
                    case 1:
                        printf("  [*] ");
                        break;
                    }
                }
                
            } else {
                int columnToPrint = 0;

                if (y<10) {
                    columnToPrint = y+1;
                } else {
                    columnToPrint = (y-10)+1;
                }
                
                if (columnToPrint<10) {
                    printf("    0%d", columnToPrint);    
                } else if (columnToPrint == 10) {
                    printf("   %d ", columnToPrint);
                }

                if (y == 9) {
                    printf("   |  #");
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
    for (int x=0; x<10; x++) {
        for (int y=0; y<10; y++) {
            printf("%d, ", field[x][y]);
        }
        printf("\n");
    }
}

int getShipSize (char ship) {
    switch (ship)
    {
    case 'd': return 2;
        break;

    case 's': return 3;
        break;

    case 'r': return 3;
        break;

    case 'b': return 4;
        break;

    case 'a': return 5;
        break;

    default: break;
    }
}

int getShipQtd (char ship) {
    switch (ship)
    {
    case 'd':
        return 5;
        break;

    case 's':
        return 4;
        break;

    case 'r':
        return 3;
        break;

    case 'b':
        return 2;
        break;

    case 'a':
        return 1;
        break;

    default:
        break;
    }
}

int isPlaceable(int x, int y, int field[10][10], int size, char direction) {
    int placeable = 0;
    
    for (int i=0; i<size; i++) {

        if (direction == 'h' || direction == 0) {

            if (field [x] [y+i] == 2 || y+i < 0 || y+i >= 10){
                return 0;
            } else {
                placeable = 1;
            }
        } else if (direction == 'v'  || direction == 1) {
            
            if (field [x+i] [y] == 2 || x+i < 0 || x+i >=10){
                return 0;
            } else {
                placeable = 1;
            }
        }
    }

    return placeable;
}

void placeUserShips (int field [10][10], char ship) {
    int shipsPlaced = 0, line = 0, column = 0;
    char direction, *shipName = getShipName(ship);

    while (shipsPlaced < getShipQtd(ship)){
        printf("Place the %s no%d. They occupie %d squares\n", shipName, shipsPlaced+1, getShipSize(ship));
        drawField(field);
        puts("Choose the line (A - J): ");
        scanf("%d", &line);
        line = line - 1;

        puts ("Choose the column (01 - 10): ");
        scanf("%d", &column);
        column = column -1;

        puts("Which direction does the ship go (V / H)?");
        scanf(" %c", &direction);
        direction = tolower(direction);

        if (isPlaceable(line, column, field, getShipSize(ship), direction)) {
            for (int i=0; i<getShipSize(ship); i++) {
                switch (direction)
                {
                case 'h':
                    field [line] [column+i] = 2;
                    break;
        
                case 'v':
                    field [line+i] [column] = 2;
                    break;
                }
            }
            shipsPlaced++;
            system("clear");
        } else {
            system("clear");
            puts("You cannot place a ship there!!!\n\n");
            sleep(2);
        }
    }
}

void placeBotShips (int field [10][10]) {
    int shipsPlaced = 0, x = 0, y = 0, direction = 0;
    int c = 0;
    char ship = 'd';

    while (c<5) {
        shipsPlaced = 0;

        while (shipsPlaced < getShipQtd(ship)){
            x = rand() % 10;
            y = rand() % 10;
            direction = rand() % 2;
            
            if (isPlaceable(x, y, field, getShipSize(ship), direction)) {
                for (int i=0; i<getShipSize(ship); i++) {
                    switch (direction)
                    {
                    case 0:
                        field [x] [y+i] = 2;
                        break;
            
                    case 1:
                        field [x+i] [y] = 2;
                        break;
                    }
                }
                shipsPlaced++;
            } else {
                
            }
        }
        c++;
        switch (c)
        {
        case 1: ship = 's'; break;
        case 2: ship = 'r'; break; 
        case 3: ship = 'b'; break;
        case 4: ship = 'a'; break;
        default: break;
        }
    }
}

void main () {
    char choice;
    int playerField [10][10];
    int botField [10][10];

    srand(time(NULL));

    initField(playerField);
    initField(botField);

    system("clear");

    //puts("=== Welcome to Battleship ===");
//
    // puts("\nIn this game you and your opponent have to place some ships in the ocean, they're:");
    // puts("\n\t|  qt  |      type     |  size  |");
    // puts("\n\t|  05  |   destroyers  |   02   |");
    // puts("\t|  04  |   submarines  |   03   |");
    // puts("\t|  03  |     cruiser   |   03   |");
    // puts("\t|  02  |   battleship  |   04   |");
    // puts("\t|  01  |     carrier   |   05   |");

    //printf("\n\nStart game? (Y/N) ");
    //scanf("%c", &choice);
    //choice = tolower(choice);

    //while (choice == 'y') 
        //system("clear");
    //
        //puts("Guess where your enemy's ships are. Choose wisely");
        //puts("The game has begun");
//
        //sleep(5);

        // placeUserShips(playerField, 'd');
        // placeUserShips(playerField, 's');
        // placeUserShips(playerField, 'r');
        // placeUserShips(playerField, 'b');
        // placeUserShips(playerField, 'a');

        drawBothField(playerField, botField);
        

        choice = 'n';
//    }
    //debugField(playerField);
    //debugField(botField);
}