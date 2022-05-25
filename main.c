#include <stdio.h>
#include <stdlib.h>


struct lines{
    int numbers[9];
};

struct sudoku{
    struct lines line[9];
};
int main()
{

    displaySudoku();
    return 0;
}


