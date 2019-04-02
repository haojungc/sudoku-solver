#include "sudoku.h"
using namespace std;

int main()
{
    int su_in[Sudoku::sudokuSize], type, x, y;
    Sudoku su;

    // set map
    for(int i = 0; i < 81; i++)
        cin >> su_in[i];
    su.setMap(su_in);

    // enter command
    while(cin >> type, type){
        switch(type){
        case 1: // swap number
            cin >> x >> y;
            su.swapNum(x, y);
            break;

        case 2: // swap row
            cin >> x >> y;
            su.swapRow(x, y);
            break;

        case 3: // swap column
            cin >> x >> y;
            su.swapCol(x, y);
            break;

        case 4: // rotate
            cin >> x;
            su.rotate(x);
            break;

        case 5: // flip
            cin >> x;
            su.flip(x);
            break;

        default:
            cout << "Error: Wrong Command" << endl;
            exit(1);
            break;
        }
    }

    // show result
    su.showMap();

    return 0;
}
