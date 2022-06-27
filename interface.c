#include <string.h>
#include <windows.h>
#include <stdio.h>

#include "interface.h"
#include "convert.h"
#include "difficulty.h"
#include "save.h"

//gameobject beinhaltet sowohl alle Zahlen des Sudokus, die vorgegebenen Zahlen und die Lösung des Sudokus als auch die verstrichene Zeit.
struct gameobject
{
    char sudokunumbers[9][9];
    char preset[9][9];
    char solution[9][9];
    int seconds;
    int minutes;

};

int valid_input (char input[], int mask)
{

    int row, column;
    char input_number;

    //Maske 1(Hauptmenü): Mögliche Eingaben, 1 = Neues Spiel, 2 = Sudoku-Regeln, S = Speichern des derzeitigen Sudokus, L = Laden eines Spielstands, X = Beenden des Programms
    if (mask == 1)
    {

        if (strlen(input) > 1)
        {
            printf("Ungueltige Eingabe, bitte geben Sie nur ein Zeichen ein.\n");
            return mask;
        }
        else if (input[0] == '1')
        {
            return 2;
        }
        else if (input[0] == '2')
        {
            printf("Sudoku hat zwei einfache Regeln: Jede Spalte, jede Zeile und jeder Block muss alle Zahlen von 1 bis 9 enthalten.\nDeshalb darf keine Spalte, keine Zeile und kein Block zwei oder mehr Felder mit derselben Zahl enthalten.\n\n\n");
            return mask;
        }
        else if (input[0] == 'S' )
        {
            savegame(Sudoku);
            return mask;
        }
        else if (input[0] == 'L')
        {
            starttimestamp = time(0);
            Sudoku = loadgame();
            return 3;
        }
        else if (input[0] == 'X')
        {
            return mask-1;
        }
        else
        {
            printf("Ungueltige Eingabe, bitte geben Sie eins der vorgegebenen Zeichen ein.\n");
            return mask;
        }

    }
    //Wahl des Schwierigkeitsgrads
    else if (mask == 2)
    {
        if (strlen(input) != 1)
        {
            printf("Ungueltige Eingabe, bitte geben Sie nur ein Zeichen ein.\n");
            return mask;
        }
        else if (input[0] == '1')
        {
            easy();
            starttimestamp = time(0);
            return 3;
        }
        else if (input[0] == '2')
        {
            medium();
            starttimestamp = time(0);
            return 3;
        }
        else if (input[0] == '3')
        {
            hard();
            starttimestamp = time(0);
            return 3;
        }
        else if (input[0] == 'X')
        {
            return 1;
        }
    }
    //Sudokufeld anzeigen, Optionen S = Speichern, X = Zum Hauptmenü
    else if (mask == 3)
    {
        if (strlen(input) == 1)
        {
            if (input[0] == 'X')
            {
                return 1;
            }
            else if (input[0] == 'S')
            {
                savegame(Sudoku);
                printf("Der Spielstand wurde gespeichert\n");
                return 3;
            }
        }

        //Auswahl eines Feldes:
        if (strlen(input) > 2)
        {
            printf("Ungueltige Eingabe, bitte ein valides Spielfeld eingeben (A1-I9), speichern (S) oder beenden (X): \n");
            return mask;
        }

        if ((input[0] >= 'A' && input[0] <= 'I') && (input[1] >= '1' && input[1] <= '9'))
        {

            row = convertchar(input);
            column = convertint(input);
            printf("Welche Zahl soll eingefuegt werden?\n");

            if(Sudoku.preset[row][column] != '0')
            {
                printf("Das Feld ist vorgegeben, bitte ein anderes waehlen\n");
                return mask;
            }
            else
            {

                do
                {

                    fflush(stdin); //Leeren des Inputbuffers
                    scanf("%c", &input_number);
                    if (input_number > '9' || input_number < '0')
                    {
                        printf("Geben Sie eine Zahl ein!");
                    }
                    else
                    {
                        //Einfügen der Zahl in das gewählte Spielfeld
                        Sudoku.sudokunumbers[row][column] = input_number;
                        printf("%c\n\n", Sudoku.sudokunumbers[0][0]);

                    }
                }
                while (input_number > '9' || input_number < '0');

                return 3;
            }
        }
        else
        {
            printf("Ungueltige Eingabe, bitte ein valides Spielfeld eingeben: ");
            return mask;
        }

    }
    printf("Fehlerhafte Eingabe unerkannt");
    return 100;
}




void user_interface (int mask)
{


    //Hauptmenü
    if (mask == 1)
    {
        printf("****************------------Sudoku-Programm:------------****************\n\n\n1 ----- Neues Spiel\n2 ----- Regeln\n");
        printf("S ----- Speichern\nL ----- Laden\n" );
        printf("X ----- Programm beenden\n");
    }
    //Wahl des Schwierigkeitsgrads
    else if (mask == 2)
    {
        printf("****************------------Neues Spiel------------****************\n\n\n");
        printf("1 ----- Einfach\n");
        printf("2 ----- Fortgeschritten\n");
        printf("3 ----- Schwer\n");

    }
    //Sudokufeld anzeigen
    else if (mask == 3)
    {
        //Berechnung der vergangenen Zeit
        time_t endtimestamp = time(0);
        int diffseconds;
        diffseconds  = difftime(endtimestamp,  starttimestamp);
        if(diffseconds + Sudoku.seconds >= 60)
        {
            Sudoku.minutes = ((diffseconds + Sudoku.seconds) / 60) + Sudoku.minutes;  //Minuten
            Sudoku.seconds = ((diffseconds + Sudoku.seconds) % 60);  //Sekunden
        }
        else
        {
            Sudoku.seconds = diffseconds + Sudoku.seconds;

        }
        starttimestamp = time(0);
        output();


        printf("Waehlen Sie ein Spielfeld aus (A1-I8), speichern (S) Sie oder gehen Sie zurueck zum Hauptmenue (X):\n");
    }

}


void output()
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
                        printf(" %i", y);
                    }
                    else
                    {
                        printf(" %i", y);
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

            if(Sudoku.preset[i][j] != '0')
            {
                printf(" ");//Falls man mit hintergrundfarben arbeiten möchte wird das Leerzeichen hier getrennt von der Zahl ausgegeben damit dies keine Farbe bekommt.
                set_color(11); //11 ist helles Cyan, wird verwendet um die Vorgegebenen Zahlen herauszuheben
                printf("%c", Sudoku.preset[i][j]);
                set_color(15);//15 ist die Farbe weiß, die standarmäßig in der Konsole verwendet wird

            }
            else if (Sudoku.sudokunumbers[i][j] == '0')
            {
                printf(" .");
            }
            else
            {
                printf(" %c",Sudoku.sudokunumbers[i][j]);

            }

            if(j == 8)
            {
                printf(" |");
                if(i == 3)
                {
                    printf(" Verstrichene Zeit:");
                }
                if(i == 4)
                {
                    printf(" %02i : %02i",Sudoku.minutes,Sudoku.seconds);
                }
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

//Funktion zum Ausgeben von gefärbten Feldern
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

int issolved() // gibt 1 zurück wenn das Sudoku erfolgreich gelöst wurde, sonst 0
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(Sudoku.sudokunumbers[i][j] != Sudoku.solution[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int gamecomplete() //gibe 1 zurück, wenn jedes Feld des Sudokus beschrieben ist, sonst 0
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (Sudoku.sudokunumbers[i][j] == '0')
            {
                return 0;
            }
        }
    }
    return 1;
}
