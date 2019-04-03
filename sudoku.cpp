#include "sudoku.h"
using namespace std;

// set
Sudoku::Sudoku() {
    for(int i = 0; i < sudokuSize; i++)
        map[i] = 0;
}

void Sudoku::setMap(const int set_map[]) {
    for(int i = 0; i < sudokuSize; i++)
        map[i] = set_map[i];
}

void Sudoku::setMap2d(const int set_map[]){

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            map2d[i][j] = set_map[i*9 + j];
}

// show map
void Sudoku::showMap() {
    for(int i = 0; i < sudokuSize; i++) {
        if(i % 9 == 8)
            cout << map[i] << endl;
        else
            cout << map[i] << " ";
    }
}

// transform
void Sudoku::swapNum(int x, int y) {
    for(int i = 0; i < sudokuSize; i++) {
        if(map[i] == x)
            map[i] = y;
        else if(map[i] == y)
            map[i] = x;
    }
}

void Sudoku::swapRow(int x, int y) {
    int temp[sudokuSize/3], init_xpos, init_ypos;

    // prevent large number
    x %= 3;
    y %= 3;

    // find position in map
    init_xpos = x*sudokuSize/3;
    init_ypos = y*sudokuSize/3;

    // store in temporary map
    for(int i = 0; i < sudokuSize/3; i++)
        temp[i] = map[i + init_xpos];

    // store y in x
    for(int i = 0; i < sudokuSize/3; i++)
        map[i + init_xpos] = map[i + init_ypos];

    // store temp in y
    for(int i = 0; i < sudokuSize/3; i++)
        map[i + init_ypos] = temp[i];
}

void Sudoku::swapCol(int x, int y) {
    int temp[sudokuSize/3], init_xpos, init_ypos;

    // prevent large number
    x %= 3;
    y %= 3;

    // find position in map
    init_xpos = x*3;
    init_ypos = y*3;

    // store column x in temp
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 3; j++)
            temp[j + i*3] = map[init_xpos + j + i*9];
    }

    // store y in x
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 3; j++)
            map[init_xpos + j + i*9] = map[init_ypos + j + i*9];
    }

    // store temp in y
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 3; j++)
            map[init_ypos + j + i*9] = temp[j + i*3];
    }
}

void Sudoku::rotate(int x) {
    int temp[9][9];

    // prevent large number
    x %= 4;

    // store 1D map into 2D temp
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            map2d[i][j] = map[i*9 + j];

    // rotate
    switch(x) {
    case 0: // rotate 0 degree(do nothing)
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[i][j];
        break;

    case 1: // rotate 90 degree
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[8-j][i];
        break;

    case 2: // rotate 180 degree
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[8-i][8-j];
        break;

    case 3: // rotate 270 degree
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[j][8-i];
        break;

    default:
        break;
    }

    for(int i = 0; i < 9; i++)
        for(int j = 0 ; j < 9; j++)
            map[i*9 + j] = temp[i][j];
}

void Sudoku::flip(int x) {
    int temp[9][9];

    // prevent large number
    x %= 2;

    // store map into 2D map & temporary map
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            map2d[i][j] = map[i*9 + j];

    switch(x) {
    case 0: // up-down flip
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[8-i][j];
        break;

    case 1: // left-right flip
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
                temp[i][j] = map2d[i][8-j];
        break;

    default:
        cout << "ERROR: Wrong Command\n"
             << "0: up-down flip; 1: left-right flip"
             << endl;
        exit(1);
        break;
    }

    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            map[i*9 + j] = temp[i][j];
}

// solve
bool Sudoku::checkUnity(const int (&checkMap)[9]){
    int count[10];

    // initialize
    for(int i = 0; i < 10; i++)
        count[i] = 0;

    // count
    for(int i = 0; i < 9; i++)
        count[checkMap[i]]++;

    // check
    for(int i = 1; i < 10; i++){
        if(count[i] == 2)
            return false;
    }
    return true;
}

bool Sudoku::isCorrect(){
   bool check_result;

   // check row
   for(int i = 0; i < 9; i++){
       for(int j = 0; j < 9; j++){
           checkMap[j] = map2d[i][j];
       }

       check_result = checkUnity(checkMap);
       if(check_result == false)
           return false;
   }

   // check column
   for(int i = 0; i < 9; i++){
       for(int j = 0; j < 9; j++){
           checkMap[j] = map2d[j][i];
       }

       check_result = checkUnity(checkMap);
       if(check_result == false)
           return false;
   }

   // check cell
   int count;
   for(int i = 0; i < 7; i += 3){
       for(int j = 0; j < 7; j += 3){
           count = 0;
           for(int k = 0; k < 3; k++){
               for(int w = 0; w < 3; w++)
                   checkMap[count++] = map2d[i+k][j+w];
           }

           check_result = checkUnity(checkMap);
           if(check_result == false)
               return false;
       }
   }

   return true;
}

int Sudoku::solve() {
    int total_element = 0;
    
    if(isCorrect() == false)
        return 0;

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(map2d[i][j])
                total_element++;
        }
    }

    cout << "test suceeded" << endl;
}
