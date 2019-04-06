#include "sudoku.h"
using namespace std;

int main() {
    int map_in[Sudoku::sudokuSize], solution;
    Sudoku su;

    for(int i = 0; i < Sudoku::sudokuSize; i++)
        cin >> map_in[i];

    su.setMap2d(map_in);

    solution = su.solve();

    cout << solution << endl;

    if(solution == 1)
        su.showMap2d();

    return 0;
}
