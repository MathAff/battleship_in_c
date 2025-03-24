#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#elif __linux__
    #include <unistd.h>
#elif __APPLE__
    #include <unistd.h>
#endif

void pressEnterToContinue();

void clearScreen() {
    printf("\033[H\033[J");
}

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
        return -1;
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

                case 3:
                    printf("  [x] ");
                    break;

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

void drawBothField (int userField [10][10], int botField [10][10]) {
    printf("\033[1m");

    printf ("                          PLAYER FIELD                          |                          ENEMY FIELD\n");

    for (int x = 0; x<=10; x++){
        if (x!=0){
            printf ("\033[1m%c ", toupper(getRowChar(x)));
        } else {
            printf ("#");
        }

        for (int y = 0; y <= 20; y++) {
            printf("\033[0m");
            if (x!=0) {
                if (y < 10) {
                    switch (userField[x-1][y])
                    {
                    case 0:
                        printf("\033[34m  [~] ");
                        break;
                    
                    case 1:
                        printf("\033[31m  [*] ");
                        break;
                    
                    case 2:
                        printf("\033[32m  [#] ");;
                        break;

                    case 3:
                        printf("\033[33m  [x] ");
                        break;

                    default:
                        printf("\033[34m  [~] ");
                        break;
                    }
                    printf("\033[0m");
                } else if (y == 10) {
                    if (x == 0) {
                        printf("  |  #");
                    } else {
                        printf("\033[1m  |  %c ", getRowChar(x));
                    }
                                        
                } else {
                    switch (botField[x-2][y-1])
                    {
                    case 0:
                        printf("\033[34m  [~] \033[0m");
                        break;
                    
                    case 1:
                        printf("\033[31m  [*] \033[0m");
                        break;
                    
                    case 2:
                        printf("\033[32m  [#] \033[0m");;
                        break;

                    case 3:
                        printf("\033[33m  [x] \033[0m");
                        break;

                    default:
                        printf("\033[34m  [~] \033[0m");
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
                    printf("\033[1m    0%d", columnToPrint);    
                } else if (columnToPrint == 10) {
                    printf("\033[1m   %d ", columnToPrint);
                }

                if (y == 9) {
                    printf("\033[1m   |  #");
                }
            }
        }
        
        printf("\n");
    }

    puts("\033[1m\n[~] -   Water    |  [#] -   Ship\n[x] - Hit Water  |  [*] - Hit Ship\033[0m");
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

    if (x >= 10 || x < 0 || y > 10 || y <= 0) {
        return 0;
    }
    
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

int coordinateIsValid (int x, int y) {
    if (x >= 10 || x < 0 || y >= 10 || y < 0) {
        return 0;
    } else {
        return 1;
    }
}

void placeUserShips (int field [10][10], char ship) {
    int shipsPlaced = 0, line = 0, column = 0;
    char direction, *shipName = getShipName(ship), lineChar;

    while (shipsPlaced < getShipQtd(ship)){
        printf("Place the %s no%d. They occupie %d squares\n", shipName, shipsPlaced+1, getShipSize(ship));
        drawField(field);
        puts("Choose the line (A - J): ");
        scanf(" %c", &lineChar);
        line = getRowInt(lineChar);

        puts ("Choose the column (01 - 10): ");
        scanf("%d", &column);
        getchar();
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
            clearScreen();
        } else {
            clearScreen();
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

int shootAtField (int field [10][10], int x, int y) {
    if (field[x][y] == 0) {
        return 0;
    } else if (field[x][y] == 1) {
        return 1;
    } else {
        return 2;
    }
}

void printScoreBoard(int playerScore, int botScore) {
    printf("\n\033[1m|");
    if (playerScore == botScore) {

        printf(" Your Score: %d | Enemy Score: %d", playerScore, botScore);

    } else if (playerScore < botScore) {

        printf("\033[31m Your Score: %d \033[0;1m| \033[32mEnemy Score: %d \033[0m", playerScore, botScore);
    } else {
        printf("\033[32m Your Score: %d \033[0;1m| \033[31mEnemy Score: %d \033[0m", playerScore, botScore);
    }
    printf (" |\n\n\033[0m");
}

void printBotThinking () {
    int frameCount = 4;

    printf ("\033[?25l\033[1m"); // unable cursor

    printf ("Bot Is Guessing Where Are Your Ships...");
    sleep(2);

    clearScreen();

    printf("\033[?25h\n"); // enable cursor
}

void printYouLose () {
    printf("      _____      _____        _____     ____   ____        ____                _____             ______       ______   \n");
    printf("     |\\    \\    /    /|  ____|\\    \\   |    | |    |      |    |          ____|\\    \\        ___|\\     \\  ___|\\     \\  \n");
    printf("     | \\    \\  /    / | /     /\\    \\  |    | |    |      |    |         /     /\\    \\      |    |\\     \\|     \\     \\ \n");
    printf("     |  \\____\\/    /  //     /  \\    \\ |    | |    |      |    |        /     /  \\    \\     |    |/____/||     ,_____/|\n");
    printf("      \\ |    /    /  /|     |    |    ||    | |    |      |    |  ____ |     |    |    | ___|    \\|   | ||     \\--'\\_|/\n");
    printf("       \\|___/    /  / |     |    |    ||    | |    |      |    | |    ||     |    |    ||    \\    \\___|/ |     /___/|  \n");
    printf("           /    /  /  |\\     \\  /    /||    | |    |      |    | |    ||\\     \\  /    /||    |\\     \\    |     \\____|\\ \n");
    printf("          /____/  /   | \\_____\\/____/ ||\\___\\_|____|      |____|/____/|| \\_____\\/____/ ||\\ ___\\|_____|   |____ '     /|\n");
    printf("         |`    | /     \\ |    ||    | /| |    |    |      |    |     || \\ |    ||    | /| |    |     |   |    /_____/ |\n");
    printf("         |_____|/       \\|____||____|/  \\|____|____|      |____|_____|/  \\|____||____|/  \\|____|_____|   |____|     | /\n");
}

void printYouWon () {
    printf(" _____      _____        _____     ____   ____         _____                   _____  _____   ______   \n");
    printf(" |\\    \\    /    /|  ____|\\    \\   |    | |    |       |\\    \\   _____     ____|\\    \\|\\    \\ |\\     \\  \n");
    printf(" | \\    \\  /    / | /     /\\    \\  |    | |    |       | |    | /    /|   /     /\\    \\\\\\    \\| \\     \\ \n");
    printf(" |  \\____\\/    /  //     /  \\    \\ |    | |    |       \\/     / |    ||  /     /  \\    \\\\|    \\  \\     |\n");
    printf("  \\ |    /    /  /|     |    |    ||    | |    |       /     /_  \\   \\/ |     |    |    ||     \\  |    |\n");
    printf("   \\|___/    /  / |     |    |    ||    | |    |      |     // \\  \\   \\ |     |    |    ||      \\ |    |\n");
    printf("       /    /  /  |\\     \\  /    /||    | |    |      |    |/   \\ |    ||\\     \\  /    /||    |\\ \\|    |\n");
    printf("      /____/  /   | \\_____\\/____/ ||\\___\\_|____|      |\\ ___/\\   \\|   /|| \\_____\\/____/ ||____||\\_____/|\n");
    printf("     |`    | /     \\ |    ||    | /| |    |    |      | |   | \\______/ | \\ |    ||    | /|    |/ \\|   ||\n");
    printf("     |_____|/       \\|____||____|/  \\|____|____|       \\|___|/\\ |    | |  \\|____||____|/ |____|   |___|/\n");
}

void animateCoin(int height) {
    char *frames[] = {"-", "\\", "|", "/"};
    int frameCount = 4;

    printf("\033[33;1m"); // change color to yellow
    printf("\033[?25l"); // unable cursor

    for (int i = height; i >= 0; i--) {
        clearScreen();
        for (int j = 0; j < i; j++) {
            printf("\n");
        }
        printf("%s\n", frames[(height - i) % frameCount]);
        usleep(20000);
    }

    for (int i = 1; i <= height; i++) {
        clearScreen();
        for (int j = 0; j < i; j++) {
            printf("\n");
        }
        printf("%s\n", frames[(height - i) % frameCount]);
        usleep(200000);
    }

    printf("\033[?25h"); // enable cursor
    printf("\033[0m"); // reset text style

}

int playerTurn (int playerField[10][10], int botField [10][10], int turn, int playerGuesses, int botGuesses) {
    int userTurn = 1, line=0, column=0, flag=1;
    char lineChar;

    while (flag) {
        clearScreen();
        printf("Turn no%d\n\n", turn);

        puts("It's Your Turn ");

        printScoreBoard(playerGuesses, botGuesses);
        drawBothField(playerField, botField);
        
        printf("\nWhere are the enemy's ships?\n");
        puts("Choose line (A - J)");
        scanf(" %c", &lineChar);
        line = getRowInt(lineChar);
    
        puts("Choose column (01 - 10)");
        scanf("%d", &column);
        column--;

        if (coordinateIsValid(line, column)) {
            if (botField [line][column] == 0) {
                botField[line][column] = 3;
        
                clearScreen();
                puts("You hit water T_T");
                sleep(2);
                clearScreen();
        
                userTurn = 0;
                flag = 0;
            } else if (botField[line][column] == 1 || botField [line][column] == 3) {
                puts("You already guessed that");
                sleep(2);
                flag = 1;
            } else {
                botField[line][column]=1;
                clearScreen();
                puts("You got it right!!!");
                sleep(2);
                clearScreen();
                userTurn = 1;
                flag = 0;
            }

        } else {
            puts("Coordinate is invalid");
            sleep(2);
            flag = 1;
        }
    
    }

    return userTurn;
}

int botTurn (int playerField [10][10], int botField[10][10]) {
    int line, column;
    int botTurn = 1;

    line = rand()%10;
    column = rand()%10;

    
    if (playerField [line][column] == 0) {
        playerField[line][column] = 3;
        drawBothField(playerField, botField);
        
        printf("\nBot guessed: (%c, %d)", toupper(getRowChar(line+1)), column+1);
        puts(" and hit water =D");
        botTurn = 0;
    } else if (playerField [line][column] == 2) {

        playerField[line][column]=1;
        drawBothField(playerField, botField);

        printf("\nBot guessed: (%c, %d)", toupper(getRowChar(line+1)), column+1);
        puts(" and hit your ship T_T");
        botTurn = 1;
    }
    return botTurn;
}

void pressEnterToContinue () {
    while (getchar() != '\n');

    printf("Press Enter to Continue...\n");
    getchar();
}


void main () {
    char choice;
    int playerField [10][10];
    int botField [10][10];
    int userTurn = 1, line, column;
    int playerGuesses =0, botGuesses=0;

    srand(time(NULL));

    initField(playerField);
    initField(botField);

    placeBotShips(playerField);
    placeBotShips(botField);

    clearScreen();

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
        //clearScreen();
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
        
        // puts("Who goes first? Fliping a coin...");
        // sleep(2.5);
        // clearScreen();

        // animateCoin(5);
        
        int flipCoin = rand() % 2;
        userTurn = flipCoin == 0 ? 0 : 1;
        // userTurn = 0;

        // switch (userTurn)
        // {
        // case 0:
        //     printf("  Bot goes first!!\n");
        //     break;
        
        // case 1:
        //     printf("  You go first!!\n");
        //     break;
        
        // default:
        //     break;
        // }

        // sleep(2);

        clearScreen();

        int gameRunning = 1, c=1;
        while (gameRunning){

            while (userTurn) {

                userTurn = playerTurn(playerField, botField, c, playerGuesses, botGuesses);
                if (userTurn) {
                    playerGuesses++;
                }
                
                if (playerGuesses == 4) {
                    printYouWon();
                    gameRunning = 0;
                    break;
                }
                
                c++;
            }
    
            while (!userTurn) {    
                clearScreen();
                printf("Turn no%d\n\n", c);
                
                puts("It's enemys Turn ");

                printScoreBoard(playerGuesses, botGuesses);

                userTurn = !botTurn(playerField, botField);
                char input[100];
    
                pressEnterToContinue();
                clearScreen();

                if (!userTurn) {
                    botGuesses++;
                }

                if (botGuesses == 4) {
                    printYouLose();
                    gameRunning = 0;
                    break;
                }

                c++;
            }
        }

        choice = 'n';
//    }
}