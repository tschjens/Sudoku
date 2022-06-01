#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
#include <stdlib.h>


void displaysudoku(int sudokuzahlen[9][9]);

int main()
{
    int sudokuzahlen[9][9] = {0};
    displaysudoku(sudokuzahlen);
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
    return 0;
}

void displaysudoku(int sudokuzahlen[9][9])
{
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(i == 0)
            {
                if(j % 8 == 0)
                printf("|");
            }
        }
    }


}
