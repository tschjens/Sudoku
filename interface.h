#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <time.h>

//Funktionen
int valid_input (char input[], int mask); //Pr�ft Nutzereingaben auf Richtigkeit

void user_interface (int mask); //Konsolenausgaben bzw Nutzeroberfl�che

void output(); //Ausgabe des Sudokufelds

int issolved();  //Pr�ft ob das Programm richtig gel�st ist

int gamecomplete();  //Pr�ft ob es noch offene Felder gibt

int set_color(int color);  //Farbige Hinterlegung von Zeichen (vorgegebene Sudokufelder)

//Variablen
time_t starttimestamp;  //Speichern des Startpunkts f�r den Timer

struct gameobject Sudoku;

#endif // INTERFACE_H_INCLUDED
