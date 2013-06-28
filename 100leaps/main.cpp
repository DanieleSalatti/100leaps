//
//  main.cpp
//  100leaps
//
//  Created by Daniele Salatti on 26/06/13.
//  Copyright (c) 2013 Daniele Salatti. All rights reserved.
//

#define LEFT        1
#define TOPLEFT     2
#define TOP         3
#define TOPRIGHT    4
#define RIGHT       5
#define BOTTOMRIGHT 6
#define BOTTOM      7
#define BOTTOMLEFT  8

#include <iostream>

int field[10][10];

void arrayCopy(int _from[10][10], int _to[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            _to[i][y] = _from[i][y];
        }
    }
}

void initField() {
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            field[i][y] = 0;
        }
    }
}

void printField(int _field[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            std::cout << "  " << _field[i][y];
        }
        std::cout << std::endl;
    }
}

void leap(int _field[10][10], int currentX, int currentY, int nLeap) {
    
    _field[currentX][currentY] = nLeap;
    
    //std::cout << "Leap: " << nLeap << std::endl;
    
    if (nLeap == 100) {
        printField(_field);
        return;
    }
    
    if (currentX > 2 && _field[currentX-3][currentY] == 0) { // can go left
        int _lField[10][10];
        arrayCopy(_field, _lField);
        leap(_lField, currentX-3, currentY, nLeap+1);
    }
    
    if (currentX > 1 && currentY > 1 && _field[currentX-2][currentY-2] == 0) { // can go topleft
        int _tlField[10][10];
        arrayCopy(_field, _tlField);
        leap(_tlField, currentX-2, currentY-2, nLeap+1);
    }
    
    if (currentY > 2 && _field[currentX][currentY-3] == 0) { // can go top
        int _tField[10][10];
        arrayCopy(_field, _tField);
        leap(_tField, currentX, currentY-3, nLeap+1);
    }
    
    if (currentX < 8 && currentY > 1 && _field[currentX+2][currentY-2] == 0) { // can go topright
        int _trField[10][10];
        arrayCopy(_field, _trField);
        leap(_trField, currentX+2, currentY-2, nLeap+1);
    }
    
    if (currentX < 7 && _field[currentX+3][currentY] == 0) { // can go right
        int _rField[10][10];
        arrayCopy(_field, _rField);
        leap(_rField, currentX+3, currentY, nLeap+1);
    }
    
    if (currentX < 8 && currentY < 8 && _field[currentX+2][currentY+2] == 0) { // can go bottomright
        int _trField[10][10];
        arrayCopy(_field, _trField);
        leap(_trField, currentX+2, currentY+2, nLeap+1);
    }
    
    if (currentY < 7 && _field[currentX][currentY+3] == 0) { // can go bottom
        int _tField[10][10];
        arrayCopy(_field, _tField);
        leap(_tField, currentX, currentY+3, nLeap+1);
    }
    
    if (currentX > 1 && currentY < 8 && _field[currentX-2][currentY+2] == 0) { // can go bottomleft
        int _trField[10][10];
        arrayCopy(_field, _trField);
        leap(_trField, currentX-2, currentY+2, nLeap+1);
    }
    
}

void startGame() {
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 10; y++) {
            int newField[10][10];
            arrayCopy(field, newField);
            newField[i][y] = 1;
            //printField(newField);
            leap(newField, i, y, 1);
            std::cout << std::endl << std::endl;
        }
    }
}

int main(int argc, const char * argv[])
{
    initField();
    //printField(field);
    startGame();
    return 0;
}

