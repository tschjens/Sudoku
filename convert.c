#include "convert.h"

int convertchar(char input[])
{
    switch (input[0])
    {
    case 'A':
        return 0;
        break;
    case 'B':
        return 1;
        break;
    case 'C':
        return 2;
        break;
    case 'D':
        return 3;
        break;
    case 'E':
        return 4;
        break;
    case 'F':
        return 5;
        break;
    case 'G':
        return 6;
        break;
    case 'H':
        return 7;
        break;
    case 'I':
        return 8;
        break;
    }
    return 9;
}

int convertint (char input[])
{
    switch (input[1])
    {
    case '1':
        return 0;
        break;
    case '2':
        return 1;
        break;
    case '3':
        return 2;
        break;
    case '4':
        return 3;
        break;
    case '5':
        return 4;
        break;
    case '6':
        return 5;
        break;
    case '7':
        return 6;
        break;
    case '8':
        return 7;
        break;
    case '9':
        return 8;
        break;
    }
    return 9;
}
