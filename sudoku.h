#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    static const int sudokuSize = 81;

    // set
    Sudoku();
    void setMap(const int set_map[]);
    void setMap2d(const int set_map[]);

    // show map
    void showMap();
    void showMap2d();

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
    bool isCorrect();
    bool checkUnity(const int (&checkMap)[9]);
    void update(int i, int j);
    bool delCand(int i, int j, int (&checkMap)[9]);
    bool delRowCand();
    bool delColCand();
    bool delCellCand();
    bool recursive_solve(int i, int j);
    bool checkDone();


  private:
    int map[sudokuSize];
    int map2d[9][9];
    int tempMap[9][9];
    int total_element;
    // int solution;   // 0: zero solution; 1: single solution; 2: multiple solution;
    int cand[9][9][9];  // candidates in each space; default: 1
    int total_cand[9][9];   // total number of candidates in each space; default: 9
};

#endif // SUDOKU_H
