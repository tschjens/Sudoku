#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED

//Funktionen
void savegame(); //Funktion zum speichern des derzeitigen Spielstands

struct gameobject loadgame(); //Struktur zum Laden eines Spielstands

//Variablen
struct gameobject Sudoku;

#endif // SAVE_H_INCLUDED
