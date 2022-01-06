#include <stdio.h>
#include <stdlib.h>

int array_player[500][2];
int array_snake[500][2];

int turn_player = 1;
int turn_snake = 1;

char last_player = '^';

void chaserMovement(char a) {

}

int main() {
    FILE *filepointer;
    char option, ch;
    int x, i = 0, j = 0, m, n, k, l;
    int pointer;

    filepointer = fopen("mazegame map.txt", "r");

    printf(" \n\n RULES FOR THE GAME ARE: ");
    printf(" \n  1.Press w to move the player up ");
    printf(" \n  2.Press s to move the player down ");
    printf(" \n  3.Press a to move the player left ");
    printf(" \n  4.Press d to move the player right ");
    printf("\n");

    //array size input
    int data, rows, columns;
    i = 0;
    fscanf (filepointer, "%d", &i);
    data = i;
    fscanf (filepointer, "%d", &i);
    rows = i;
    fscanf (filepointer, "%d", &i);
    columns = i;

    fscanf (filepointer, "%d", &i);

    char a[rows+2][columns+2];

    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            a[i][j] = ' ';
        }
    }

    a[0][0] = '#';
    a[0][columns-1] = '#';
    a[rows-1][0] = '#';
    a[rows-1][columns-1] = '#';
    for(int i = 1; i < columns-1; i++){
        a[0][i] = '-';
    }
    for(int i = 1; i < columns-1; i++){
        a[rows-1][i] = '-';
    }
    for(int i = 1; i < rows-1; i++){
        a[i][0] = '|';
    }
    for(int i = 1; i < rows-1; i++){
        a[i][columns-1] = '|';
    }
    //time to add values to the array
    int type, row, col;
    while (!feof (filepointer))
    {
//	    printf ("%d ", i);
        //getting values of row and column
        row = i;
        fscanf (filepointer, "%d", &i);
        col = i;

        fscanf (filepointer, "%d", &i);
        type = i;

        if(type == 0){
            array_player[0][0] = row;
            array_player[0][1] = col;
            a[row][col] = '^';
        } else if(type == 1){
            array_snake[0][0] = row;
            array_snake[0][1] = col;
            a[row][col] = '~';
        } else if(type == 2){
            a[row][col] = 'x';
        }
        else if(type == 3){
            a[row][col] = 'O';
        }
        fscanf (filepointer, "%d", &i);
    }
//	printf ("%d ", i);
    fclose(filepointer);

//    //printing to check
//    for(int i = 0; i < rows; i++){
//        for(int j = 0; j < columns; j++){
//            printf("%c", a[i][j] );
//        }
//        printf("\n");
//    }

//    while ((ch = fgetc(filepointer)) != EOF) {
//
//        printf("%c", ch);
//        if (ch != '\n') {
//            a[i][j] = ch;
//            j++;
//        } else {
//            j = 0;
//            i++;
//        }
//    }



    //something is happening here that I don't know anything about
    while (1) {
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 14; j++) {
                if ((a[i][j] == '^') || (a[i][j] == 'v') || (a[i][j] == '<') || (a[i][j] == '>')) {
                    m = i;
                    n = j;
                    array_player[turn_player][0] = m;
                    array_player[turn_player][1] = n;
                    turn_player++;
//                    last_player = a[i][j];
                }
            }
        }

        scanf("%c", &option);
        switch (option) {
            case 'w': {
 
                last_player = '^';
                if (a[m - 1][n] == 'O' || a[m - 1][n] == '-') {
                    system("cls");
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 14; j++) {
                            printf("%c", a[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                } else {

                    a[m][n] = ' ';
                    a[--m][n] = '^';

                    system("cls");

                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 14; j++) {
                            printf("%c", a[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }
            }
            case 's': {
        
                last_player = 'v';
                if (a[m + 1][n] == 'O' || a[m + 1][n] == '-') {
                    system("cls");

                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 14; j++) {
                            printf("%c", a[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }

                a[m][n] = ' ';
                a[++m][n] = 'v';
                system("cls");

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 'a': {
                last_player = '<';
                if (a[m][n - 1] == 'O' || a[m][n - 1] == '|') {
                    system("cls");

                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 14; j++) {
                            printf("%c", a[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }

                a[m][n] = ' ';
                a[m][--n] = '<';
                system("cls");

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
            case 'd': {
                last_player = '>';
                if (a[m][n + 1] == 'O' || a[m][n + 1] == '|') {
                    system("cls");

                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 14; j++) {
                            printf("%c", a[i][j]);
                        }
                        printf("\n");
                    }
                    break;
                }

                a[m][n] = ' ';
                a[m][++n] = '>';

                system("cls");

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }

            case 'u': {
                a[array_player[turn_player-1][0]][array_player[turn_player-1][1]] = ' ';
                a[array_player[turn_player-3][0]][array_player[turn_player-3][1]] = last_player;
                turn_player--;
                system("cls");
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 14; j++) {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        }
    }
    return 0;
}
