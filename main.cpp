#include <iostream>
#include <conio.h> 
using namespace std;

// Spielfeldgröße
const int SPALTEN = 80;  // horizontal
const int ZEILEN = 40;   // vertikal

const int MaxFigurSpalten = 20;
const int MaxFigurZeilen = 20;
const int StartSpalte = 40;
const int StartZeile = 20;

// Spielfeld
char Spielfeld[ZEILEN][SPALTEN] = { 0 };

// Figuren
char figur1[MaxFigurZeilen][MaxFigurSpalten] = {
    {'.', '.', '.'},
    {'*', '*', '*'},
    {'.', '.', '.'}
};

char figur2[MaxFigurZeilen][MaxFigurSpalten] = {
    {'.', '*', '.'},
    {'.', '.', '*'},
    {'*', '*', '*'}
};

char figur3[MaxFigurZeilen][MaxFigurSpalten] = {
    {'*', '*', '*'},
    {'*', '.', '*'},
    {'*', '.', '*'},
    {'.', '.', '.'},
    {'*', '.', '*'},
    {'*', '.', '*'},
    {'*', '*', '*'}
};

char figur4[MaxFigurZeilen][MaxFigurSpalten] = {
    {'*', '*', '*', '.', '*', '*', '*'},
    {'*', '.', '.', '.', '.', '.', '*'},
    {'*', '*', '*', '.', '*', '*', '*'}
};

char figur5[MaxFigurZeilen][MaxFigurSpalten] = {
    {'.', '.', '*'},
    {'*', '.', '*'},
    {'.', '*', '*'}
};

// Display initialisieren
void InitDisplay(char Matrix[ZEILEN][SPALTEN]) {
    for (int y = 0; y < ZEILEN; y++) {
        for (int x = 0; x < SPALTEN; x++) {
            Matrix[y][x] = '.';
        }
    }
}

// Figur auf Spielfeld einfügen
void FirstGeneration(char Matrix[ZEILEN][SPALTEN], char figur[MaxFigurZeilen][MaxFigurSpalten], int StartZ, int StartS) {
    for (int y = 0; y < MaxFigurZeilen; y++) {
        for (int x = 0; x < MaxFigurSpalten; x++) {
            if (figur[y][x] == '*') {
                //Nur setzen, wenn innerhalb des Spielfelds
                if (StartZ + y < ZEILEN && StartS + x < SPALTEN) {
                    Matrix[StartZ + y][StartS + x] = '*';
                }
            }
        }
    }
}

//Konsole löschen
void ClearDisplay() {
    system("cls");
}

// Spielfeld anzeigen
void ShowDisplay(char Matrix[ZEILEN][SPALTEN]) {
    for (int y = 0; y < ZEILEN; y++) {
        for (int x = 0; x < SPALTEN; x++) {
            cout << Matrix[y][x];
        }
        cout << endl;
    }
}

// Lebende Nachbarn zählen
int CountNeighbors(char Matrix[ZEILEN][SPALTEN], int y, int x) {
    int count = 0;
    for (int dy = -1; dy < 2; dy++) {
        for (int dx = -1; dx < 2; dx++) {
            int newY = (y + dy + ZEILEN) % ZEILEN;   // Vertikale bestimmung
            int newX = (x + dx + SPALTEN) % SPALTEN; // Horizontale bestimmung
            if (!(dy == 0 && dx == 0) && Matrix[newY][newX] == '*') {
                count++;
            }
        }
    }
    return count;
}

//Nächste Generation berechnen
void NextGeneration(char Matrix[ZEILEN][SPALTEN]) {
    char newMatrix[ZEILEN][SPALTEN];

    for (int y = 0; y < ZEILEN; y++) {
        for (int x = 0; x < SPALTEN; x++) {
            int neighbors = CountNeighbors(Matrix, y, x);

            if (Matrix[y][x] == '*') {
                if (neighbors == 2 || neighbors == 3)
                    newMatrix[y][x] = '*'; // Überleben
                else
                    newMatrix[y][x] = '.'; // Sterben
            }
            else {
                if (neighbors == 3)
                    newMatrix[y][x] = '*'; // Geburt
                else
                    newMatrix[y][x] = '.';
            }
        }
    }

    // Spielfeld aktualisieren
    for (int y = 0; y < ZEILEN; y++) {
        for (int x = 0; x < SPALTEN; x++) {
            Matrix[y][x] = newMatrix[y][x];
        }
    }
}


int main() {
    char ch;
    InitDisplay(Spielfeld);
    FirstGeneration(Spielfeld, figur2, StartZeile, StartSpalte);

    do {
        ClearDisplay();
        ShowDisplay(Spielfeld);
        NextGeneration(Spielfeld);
        ch = _getch(); // Auf Tastendruck warten
    } while (ch != 'q');

    return 0;
}