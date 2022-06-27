#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "interface.h"

//gameobject beinhaltet sowohl alle Zahlen des Sudokus, die vorgegebenen Zahlen und die Lösung des Sudokus als auch die verstrichene Zeit.
struct gameobject
{
    char sudokunumbers[9][9];
    char preset[9][9];
    char solution[9][9];
    int seconds;
    int minutes;
};

int main()
{
    int mask = 1;
    char user_input[255];

    memset(&Sudoku, '0', sizeof(Sudoku)); //Sudoku-Felder mit dem char '0' auffüllen
    Sudoku.minutes = 0;  //minuten und sekunden initialisieren
    Sudoku.seconds = 0;
    do
    {
        user_interface(mask);
        scanf("%s", user_input);
        user_input[0] = toupper(user_input[0]); //Eingaben immer in Uppercase umwandeln
        mask = valid_input(user_input,mask);
        fflush(stdin); //Leeren des Inputbuffers nach jedem Durchlauf

        //Ende des Spiels feststellen
        if (gamecomplete())
        {
            if (issolved())
            {
                printf("Das Sudoku wurde richtig geloest!");
                printf("\n Das Programm wird nun beendet.\n");
                mask = 0;
            } else
            {
                printf("Sie haben mindestens einen Fehler gemacht.");
            }
        }
    }while (mask > 0);

    return 0;
}
