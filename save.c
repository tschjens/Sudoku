#include <stdio.h>
#include <stdlib.h>

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

//Laden eines Spielstands, enthält sowohl Sudokupreset,Nutzereingaben und Lösung als auch derzeitige Spielzeit
struct gameobject loadgame()
{
    struct gameobject *object = malloc(sizeof(struct gameobject));
    FILE * file= fopen("savegame.txt", "rb");
    if (file != NULL)
    {
        fread(object, sizeof(struct gameobject), 1, file);
        fclose(file);
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                Sudoku.sudokunumbers[i][j] = object->sudokunumbers[i][j];
                Sudoku.solution[i][j] = object->solution[i][j];
                Sudoku.preset[i][j] = object->preset[i][j];

            }
        }
        Sudoku.minutes = object->minutes;
        Sudoku.seconds = object->seconds;
    }
    return(Sudoku);
}

//Speichern eines Spielstands, enthält sowohl Sudokupreset,Nutzereingaben und Lösung als auch derzeitige Spielzeit
//Falls noch keine Datei existiert wird eine mit dem Namen savegame.txt in dem Ordner des Programmes angelegt
void savegame(struct gameobject zahlen)
{
    struct gameobject *object = malloc(sizeof(struct gameobject));
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            object->sudokunumbers[i][j] = Sudoku.sudokunumbers[i][j];
            object->solution[i][j] = Sudoku.solution[i][j];
            object->preset[i][j] = Sudoku.preset[i][j];

        }
    }
    object->minutes = Sudoku.minutes;
    object->seconds = Sudoku.seconds;
    FILE * file= fopen("savegame.txt", "wb");
    if (file != NULL)
    {
        fwrite(object, sizeof(struct gameobject), 1, file);
        fclose(file);
    }
}
