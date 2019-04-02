#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku
{
public:
    static const int sudokuSize = 81;
    
    // set
    Sudoku();
    void setMap(const int set_map[]);

    // show map
    void showMap();

    // generate
    static Sudoku generate();

    // transform
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    int solve();


private:
    int map[sudokuSize];
};

#endif // SUDOKU_H
