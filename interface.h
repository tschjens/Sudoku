#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <time.h>

//Funktionen
int valid_input (char input[], int mask); //Prüft Nutzereingaben auf Richtigkeit

void user_interface (int mask); //Konsolenausgaben bzw Nutzeroberfläche

void output(); //Ausgabe des Sudokufelds

int issolved();  //Prüft ob das Programm richtig gelöst ist

int gamecomplete();  //Prüft ob es noch offene Felder gibt

int set_color(int color);  //Farbige Hinterlegung von Zeichen (vorgegebene Sudokufelder)

//Variablen
time_t starttimestamp;  //Speichern des Startpunkts für den Timer

struct gameobject Sudoku;

#endif // INTERFACE_H_INCLUDED
