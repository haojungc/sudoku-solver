#include "sudoku.h"
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    Sudoku su;
    int x, y;
    int sample1[Sudoku::sudokuSize] = {
        0, 0, 0, 0, 1, 2, 0, 0, 0,
        0, 0, 3, 6, 0, 0, 8, 7, 0,
        6, 9, 0, 0, 0, 0, 0, 0, 3,
        0, 0, 0, 8, 6, 0, 0, 0, 4,
        0, 5, 8, 0, 0, 0, 1, 2, 0,
        3, 0, 0, 0, 2, 4, 0, 0, 0,
        2, 0, 0, 0, 0, 0, 0, 3, 1,
        0, 1, 5, 0, 0, 7, 4, 0, 0,
        0, 0, 0, 4, 9, 0, 0, 0, 0
    };
    int sample2[Sudoku::sudokuSize] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 6, 9, 0, 3, 5, 0, 7, 1,
        4, 0, 0, 8, 0, 0, 3, 0, 0,
        0, 0, 4, 0, 0, 1, 0, 0, 5,
        0, 1, 0, 0, 9, 0, 0, 6, 0,
        2, 0, 0, 3, 0, 0, 1, 0, 0,
        0, 0, 8, 0, 0, 9, 0, 0, 4,
        1, 2, 0, 5, 6, 0, 7, 8, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0
    };
    int sample3[Sudoku::sudokuSize] = {
        0, 0, 0, 4, 0, 0, 0, 0, 9,
        1, 0, 0, 6, 0, 0, 0, 7, 0,
        0, 0, 2, 0, 5, 0, 8, 0, 0,
        0, 5, 0, 7, 0, 0, 0, 0, 0,
        4, 0, 0, 0, 0, 0, 0, 0, 1,
        0, 0, 0, 0, 0, 8, 0, 2, 0,
        0, 0, 7, 0, 2, 0, 6, 0, 0,
        0, 8, 0, 0, 0, 3, 0, 0, 5,
        9, 0, 0, 0, 0, 1, 0, 0, 0
    };

    switch(rand()%3 + 1) {
    case 1:
        su.setMap(sample1);
        break;
    case 2:
        su.setMap(sample2);
        break;
    case 3:
        su.setMap(sample3);
        break;
    default:
        break;
    }

    for(int i = 0; i < 10; i++) {
        // generate random x & y; range: 0~8
        x = rand() % 9;
        while(1) {
            y = rand() % 9;
            if(y != x) break;
        }

        switch(rand()%5 + 1) {
        case 1: // swap number
            su.swapNum(x+1, y+1);
            break;
        case 2: // swap row
            su.swapRow(x, y);
            break;
        case 3: // swap column
            su.swapCol(x, y);
            break;
        case 4: // rotate
            su.rotate(x);
            break;
        case 5: // flip
            su.flip(x);
            break;
        default:
            break;
        }
    }

    su.showMap();

    return 0;
}
