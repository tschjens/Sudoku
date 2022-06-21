#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int set_color(int color);
struct gameobject fillgameobject(struct gameobject input);
void output(struct gameobject zahlen);
void savegame(struct gameobject zahlen);

struct gameobject
{
    int sudokuzahlen[9][9];
    int vorgabe[9][9];
    int loesung[9][9];
};

int main()
{
    struct gameobject zahlen =
    {
        .sudokuzahlen = {0},
        .loesung = {0}

    };



    zahlen.vorgabe[0][2] = 8;
    zahlen.vorgabe[0][6] = 2;
    zahlen.vorgabe[1][1] = 1;
    zahlen.vorgabe[1][3] = 3;
    zahlen.vorgabe[1][5] = 7;
    zahlen.vorgabe[1][7] = 5;
    zahlen.vorgabe[2][0] = 5;
    zahlen.vorgabe[2][1] = 4;
    zahlen.vorgabe[2][7] = 7;
    zahlen.vorgabe[2][8] = 6;
    zahlen.vorgabe[3][2] = 7;
    zahlen.vorgabe[3][3] = 5;
    zahlen.vorgabe[3][5] = 4;
    zahlen.vorgabe[3][6] = 6;
    zahlen.vorgabe[4][0] = 8;
    zahlen.vorgabe[4][8] = 1;
    zahlen.vorgabe[5][2] = 6;
    zahlen.vorgabe[5][3] = 1;
    zahlen.vorgabe[5][5] = 2;
    zahlen.vorgabe[5][6] = 8;
    zahlen.vorgabe[6][0] = 4;
    zahlen.vorgabe[6][1] = 9;
    zahlen.vorgabe[6][7] = 6;
    zahlen.vorgabe[6][8] = 2;
    zahlen.vorgabe[7][1] = 8;
    zahlen.vorgabe[7][3] = 7;
    zahlen.vorgabe[7][5] = 6;
    zahlen.vorgabe[7][7] = 3;
    zahlen.vorgabe[8][2] = 3;
    zahlen.vorgabe[8][6] = 9;


    output(zahlen);
    /*    char auswahl = ' ';
        do{
            printf("+++Sudoku+++\n");
            printf("n = Neues Spiel\n");
            printf("x = Spiel beenden\n");
            scanf("%c",&auswahl);
        }while(auswahl != 'x' && auswahl != 'n');

        if(auswahl == 'n' || auswahl == 'N')
        {
            printf("1 = leichtes  Spiel\n");
            printf("1 = mittleres Spiel\n");
            printf("1 = schweres  Spiel\n");
            printf("1 = Eigenes Sudoku importieren\n");

        }


    */
    savegame(zahlen);
    return 0;
}

struct gameobject fillgameobject(struct gameobject input)
{
    struct gameobject zahlen;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            zahlen.loesung[i][j] = input.loesung[i][j];
            zahlen.sudokuzahlen[i][j] = input.sudokuzahlen[i][j];
            zahlen.vorgabe[i][j] = input.vorgabe[i][j];
        }
    }
    return zahlen;
};

void savegame(struct gameobject zahlen)
{
    /*
        FILE *file;

        file = fopen("savegame.txt", "wb");

        if(file != NULL)
        {
            fwrite(zahlen, sizeof(struct gameobject), 1,file);
        }

        fclose(file);
        */
    struct gameobject *object = malloc(sizeof(struct gameobject));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            object->sudokuzahlen[i][j] = (int)zahlen.sudokuzahlen[i][j];
            object->loesung[i][j] = (int)zahlen.loesung[i][j];
            object->vorgabe[i][j] = (int)zahlen.vorgabe[i][j];
        }
    }
    // *object = fillgameobject(zahlen);
    FILE * file= fopen("savegame.txt", "wb");

    if (file != NULL)
    {
        fwrite(object, sizeof(struct gameobject), 1, file);
        fclose(file);
    }
}



void output(struct gameobject zahlen)
{


    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(i == 0 && j == 0)
            {
                for(int y = 1; y <= 9; y++)
                {
                    if(y == 1)
                    {
                        printf("  |");
                        printf(" %i",y);
                    }
                    else
                    {
                        printf(" %i",y);
                        if(y % 3 == 0)
                        {
                            printf(" |");
                        }
                    }
                }
                printf("\n--+-------+-------+-------+");
                printf("\n");
            }
            if(j == 0)
            {
                switch (i)
                {
                case 0:
                    printf("A");
                    break;
                case 1:
                    printf("B");
                    break;
                case 2:
                    printf("C");
                    break;
                case 3:
                    printf("D");
                    break;
                case 4:
                    printf("E");
                    break;
                case 5:
                    printf("F");
                    break;
                case 6:
                    printf("G");
                    break;
                case 7:
                    printf("H");
                    break;
                case 8:
                    printf("I");
                    break;
                }
                printf(" |");


            }
            else if(j % 3 == 0)
            {
                printf(" |");
            }

            if(zahlen.vorgabe[i][j] != 0)
            {
                printf(" ");
                set_color(12); //71 || 12
                printf("%i", zahlen.vorgabe[i][j]);
                set_color(15);

            }
            else if (zahlen.sudokuzahlen[i][j] == 0)
            {
                printf(" .");
            }
            else
            {
                printf(" %i",zahlen.sudokuzahlen[i][j]);

            }
            if(j == 8)
            {
                printf(" |");
            }
        }
        if(i % 3 - 2 == 0 && i != 0)
        {
            printf("\n--+-------+-------+-------+");
        }
        printf("\n");
    }
}

/**Funktion aus dem Programm: KonsolenDemo Windows v0.3**/
/**Funktion verwendet int statt einem Char da die bedienung so leichter ist**/
int set_color(int color)
{
    int set_color_failed = 0;

    HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hstdout, &csbi);

    set_color_failed = SetConsoleTextAttribute(hstdout, color);

    // reverse "wrong" return value from Windows API
    return set_color_failed ? 0 : 1;
}


