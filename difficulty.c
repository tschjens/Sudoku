#include "difficulty.h"

struct gameobject
{
    char sudokunumbers[9][9]; //Nutzereingaben im Sudokuspiel und vorgegebene Felder
    char preset[9][9];  //Nur die vorgegebenen Felder
    char solution[9][9];  //Alle Felder
    int seconds;  //Verstrichene Sekunden
    int minutes;  // Verstrichene Minuten
};

//Sudoku Presets, ein einfaches, ein mittleres und ein schweres.

void easy()
{
    Sudoku.preset[0][2] = '8';
    Sudoku.preset[0][6] = '2';

    Sudoku.preset[1][1] = '1';
    Sudoku.preset[1][3] = '3';
    Sudoku.preset[1][5] = '7';
    Sudoku.preset[1][7] = '5';

    Sudoku.preset[2][0] = '5';
    Sudoku.preset[2][1] = '4';
    Sudoku.preset[2][7] = '7';
    Sudoku.preset[2][8] = '6';

    Sudoku.preset[3][2] = '7';
    Sudoku.preset[3][3] = '5';
    Sudoku.preset[3][5] = '4';
    Sudoku.preset[3][6] = '6';

    Sudoku.preset[4][0] = '8';
    Sudoku.preset[4][8] = '1';

    Sudoku.preset[5][2] = '6';
    Sudoku.preset[5][3] = '1';
    Sudoku.preset[5][5] = '2';
    Sudoku.preset[5][6] = '8';

    Sudoku.preset[6][0] = '4';
    Sudoku.preset[6][1] = '9';
    Sudoku.preset[6][7] = '6';
    Sudoku.preset[6][8] = '2';

    Sudoku.preset[7][1] = '8';
    Sudoku.preset[7][3] = '7';
    Sudoku.preset[7][5] = '6';
    Sudoku.preset[7][7] = '3';

    Sudoku.preset[8][2] = '3';
    Sudoku.preset[8][6] = '9';


    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Sudoku.solution[i][j] = Sudoku.preset[i][j];
            Sudoku.sudokunumbers[i][j] = Sudoku.preset[i][j];
        }
    }

    //Lösungsarray füllen.

    Sudoku.solution[0][0] = '3';
    Sudoku.solution[0][1] = '7';
    Sudoku.solution[0][3] = '4';
    Sudoku.solution[0][4] = '6';
    Sudoku.solution[0][5] = '5';
    Sudoku.solution[0][7] = '1';
    Sudoku.solution[0][8] = '9';

    Sudoku.solution[1][0] = '6';
    Sudoku.solution[1][2] = '9';
    Sudoku.solution[1][4] = '2';
    Sudoku.solution[1][6] = '4';
    Sudoku.solution[1][8] = '8';

    Sudoku.solution[2][2] = '2';
    Sudoku.solution[2][3] = '9';
    Sudoku.solution[2][4] = '1';
    Sudoku.solution[2][5] = '8';
    Sudoku.solution[2][6] = '3';

    Sudoku.solution[3][0] = '1';
    Sudoku.solution[3][1] = '2';
    Sudoku.solution[3][4] = '8';
    Sudoku.solution[3][7] = '9';
    Sudoku.solution[3][8] = '3';

    Sudoku.solution[4][1] = '3';
    Sudoku.solution[4][2] = '4';
    Sudoku.solution[4][3] = '6';
    Sudoku.solution[4][4] = '7';
    Sudoku.solution[4][5] = '9';
    Sudoku.solution[4][6] = '5';
    Sudoku.solution[4][7] = '2';


    Sudoku.solution[5][0] = '9';
    Sudoku.solution[5][1] = '5';
    Sudoku.solution[5][4] = '3';
    Sudoku.solution[5][7] = '4';
    Sudoku.solution[5][8] = '7';

    Sudoku.solution[6][2] = '1';
    Sudoku.solution[6][3] = '8';
    Sudoku.solution[6][4] = '5';
    Sudoku.solution[6][5] = '3';
    Sudoku.solution[6][6] = '7';

    Sudoku.solution[7][0] = '2';
    Sudoku.solution[7][2] = '5';
    Sudoku.solution[7][4] = '9';
    Sudoku.solution[7][6] = '1';
    Sudoku.solution[7][8] = '4';

    Sudoku.solution[8][0] = '7';
    Sudoku.solution[8][1] = '6';
    Sudoku.solution[8][3] = '2';
    Sudoku.solution[8][4] = '4';
    Sudoku.solution[8][5] = '1';
    Sudoku.solution[8][7] = '8';
    Sudoku.solution[8][8] = '5';
}
void medium()
{
    Sudoku.preset[0][0] = '5';
    Sudoku.preset[0][5] = '7';
    Sudoku.preset[0][7] = '9';
    Sudoku.preset[0][8] = '8';

    Sudoku.preset[1][1] = '1';
    Sudoku.preset[1][3] = '5';

    Sudoku.preset[2][1] = '7';
    Sudoku.preset[2][4] = '2';

    Sudoku.preset[3][6] = '3';
    Sudoku.preset[3][7] = '1';

    Sudoku.preset[4][3] = '2';

    Sudoku.preset[5][0] = '1';
    Sudoku.preset[5][1] = '3';
    Sudoku.preset[5][2] = '6';
    Sudoku.preset[5][5] = '9';
    Sudoku.preset[5][6] = '8';
    Sudoku.preset[5][7] = '7';

    Sudoku.preset[6][2] = '9';
    Sudoku.preset[6][6] = '4';

    Sudoku.preset[7][3] = '9';
    Sudoku.preset[7][7] = '8';

    Sudoku.preset[8][0] = '3';
    Sudoku.preset[8][4] = '8';
    Sudoku.preset[8][7] = '2';
    Sudoku.preset[8][8] = '5';

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Sudoku.solution[i][j] = Sudoku.preset[i][j];
            Sudoku.sudokunumbers[i][j] = Sudoku.preset[i][j];
        }
    }

    Sudoku.solution[0][1] = '6';
    Sudoku.solution[0][2] = '4';
    Sudoku.solution[0][3] = '1';
    Sudoku.solution[0][4] = '3';
    Sudoku.solution[0][6] = '2';

    Sudoku.solution[1][0] = '8';
    Sudoku.solution[1][2] = '2';
    Sudoku.solution[1][4] = '9';
    Sudoku.solution[1][5] = '4';
    Sudoku.solution[1][6] = '6';
    Sudoku.solution[1][7] = '3';
    Sudoku.solution[1][8] = '7';

    Sudoku.solution[2][0] = '9';
    Sudoku.solution[2][2] = '3';
    Sudoku.solution[2][3] = '8';
    Sudoku.solution[2][5] = '6';
    Sudoku.solution[2][6] = '1';
    Sudoku.solution[2][7] = '5';
    Sudoku.solution[2][8] = '4';


    Sudoku.solution[3][0] = '4';
    Sudoku.solution[3][1] = '2';
    Sudoku.solution[3][2] = '5';
    Sudoku.solution[3][3] = '7';
    Sudoku.solution[3][4] = '6';
    Sudoku.solution[3][5] = '8';
    Sudoku.solution[3][8] = '9';

    Sudoku.solution[4][0] = '7';
    Sudoku.solution[4][1] = '9';
    Sudoku.solution[4][2] = '8';
    Sudoku.solution[4][4] = '1';
    Sudoku.solution[4][5] = '3';
    Sudoku.solution[4][6] = '5';
    Sudoku.solution[4][7] = '4';
    Sudoku.solution[4][8] = '6';

    Sudoku.solution[5][3] = '4';
    Sudoku.solution[5][4] = '5';
    Sudoku.solution[5][8] = '2';

    Sudoku.solution[6][0] = '2';
    Sudoku.solution[6][1] = '8';
    Sudoku.solution[6][3] = '3';
    Sudoku.solution[6][4] = '7';
    Sudoku.solution[6][5] = '5';
    Sudoku.solution[6][7] = '6';
    Sudoku.solution[6][8] = '1';

    Sudoku.solution[7][0] = '6';
    Sudoku.solution[7][1] = '5';
    Sudoku.solution[7][2] = '1';
    Sudoku.solution[7][4] = '4';
    Sudoku.solution[7][5] = '2';
    Sudoku.solution[7][6] = '7';
    Sudoku.solution[7][8] = '3';


    Sudoku.solution[8][1] = '4';
    Sudoku.solution[8][2] = '7';
    Sudoku.solution[8][3] = '6';
    Sudoku.solution[8][5] = '1';
    Sudoku.solution[8][6] = '9';
}
void hard()
{
    Sudoku.preset[0][2] = '1';
    Sudoku.preset[0][6] = '7';

    Sudoku.preset[1][0] = '6';
    Sudoku.preset[1][5] = '7';
    Sudoku.preset[1][6] = '2';
    Sudoku.preset[1][7] = '1';

    Sudoku.preset[2][1] = '7';
    Sudoku.preset[2][2] = '4';

    Sudoku.preset[3][0] = '1';
    Sudoku.preset[3][4] = '8';
    Sudoku.preset[3][7] = '5';

    Sudoku.preset[4][5] = '5';
    Sudoku.preset[4][6] = '3';

    Sudoku.preset[5][1] = '5';
    Sudoku.preset[5][3] = '1';
    Sudoku.preset[5][8] = '8';

    Sudoku.preset[6][7] = '2';

    Sudoku.preset[7][0] = '8';
    Sudoku.preset[7][1] = '9';
    Sudoku.preset[7][5] = '2';
    Sudoku.preset[7][7] = '3';

    Sudoku.preset[8][2] = '7';
    Sudoku.preset[8][3] = '5';
    Sudoku.preset[8][4] = '3';
    Sudoku.preset[8][5] = '1';
    Sudoku.preset[8][6] = '9';

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            Sudoku.solution[i][j] = Sudoku.preset[i][j];
            Sudoku.sudokunumbers[i][j] = Sudoku.preset[i][j];
        }
    }

    Sudoku.solution[0][0] = '9';
    Sudoku.solution[0][1] = '2';
    Sudoku.solution[0][3] = '3';
    Sudoku.solution[0][4] = '6';
    Sudoku.solution[0][5] = '8';
    Sudoku.solution[0][7] = '4';
    Sudoku.solution[0][8] = '5';

    Sudoku.solution[1][1] = '8';
    Sudoku.solution[1][2] = '3';
    Sudoku.solution[1][3] = '4';
    Sudoku.solution[1][4] = '5';
    Sudoku.solution[1][8] = '9';

    Sudoku.solution[2][0] = '5';
    Sudoku.solution[2][3] = '2';
    Sudoku.solution[2][4] = '1';
    Sudoku.solution[2][5] = '9';
    Sudoku.solution[2][6] = '8';
    Sudoku.solution[2][7] = '6';
    Sudoku.solution[2][8] = '3';

    Sudoku.solution[3][1] = '3';
    Sudoku.solution[3][2] = '9';
    Sudoku.solution[3][3] = '7';
    Sudoku.solution[3][5] = '6';
    Sudoku.solution[3][6] = '4';
    Sudoku.solution[3][8] = '2';

    Sudoku.solution[4][0] = '4';
    Sudoku.solution[4][1] = '6';
    Sudoku.solution[4][2] = '8';
    Sudoku.solution[4][3] = '9';
    Sudoku.solution[4][4] = '2';
    Sudoku.solution[4][7] = '7';
    Sudoku.solution[4][8] = '1';

    Sudoku.solution[5][0] = '7';
    Sudoku.solution[5][2] = '2';
    Sudoku.solution[5][4] = '4';
    Sudoku.solution[5][5] = '3';
    Sudoku.solution[5][6] = '6';
    Sudoku.solution[5][7] = '9';

    Sudoku.solution[6][0] = '3';
    Sudoku.solution[6][1] = '1';
    Sudoku.solution[6][2] = '6';
    Sudoku.solution[6][3] = '8';
    Sudoku.solution[6][4] = '9';
    Sudoku.solution[6][5] = '4';
    Sudoku.solution[6][6] = '5';
    Sudoku.solution[6][8] = '7';

    Sudoku.solution[7][2] = '5';
    Sudoku.solution[7][3] = '6';
    Sudoku.solution[7][4] = '7';
    Sudoku.solution[7][6] = '1';
    Sudoku.solution[7][8] = '4';

    Sudoku.solution[8][0] = '2';
    Sudoku.solution[8][1] = '4';
    Sudoku.solution[8][7] = '8';
    Sudoku.solution[8][8] = '6';
}

