#include<iostream>
#include<vector>
using namespace std;

#define UNASSIGNED 0

class sudoku{

    vector<vector<int> > grid;

    public:
    sudoku(vector<vector<int> > nos){
        grid = nos;
    }

    bool solveSudoku();
    bool findUnassignedGridLocation(int &, int &);
    bool isSafe(int, int, int);
    bool UsedInBox(int, int, int);
    bool UsedInRow(int, int);
    bool UsedInCol(int, int);
    void printBoard();
    void printFancyBoard();
};

bool sudoku::solveSudoku(){

    int row, col;
    if(!findUnassignedGridLocation(row, col))
        return true;

    for(int digit=1;digit<=9;++digit)
        if(isSafe(row, col, digit)){
            grid[row][col] = digit;
            if(solveSudoku())
                return true;
            grid[row][col] = UNASSIGNED;
        }
    return false;

}

bool sudoku::findUnassignedGridLocation(int &row, int &col){
    for(row=0;row<9;++row)
        for(col=0;col<9;++col)
            if(grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

bool sudoku::UsedInRow(int row, int num){
    for(int col=0;col<9;++col)
        if(grid[row][col] == num)
            return true;
    return false;
}

bool sudoku::UsedInCol(int col, int num){
    for(int row=0;row<9;++row)
        if(grid[row][col] == num)
            return true;
    return false;
}

bool sudoku::UsedInBox(int startrow, int startcol, int num){
    for(int row=0;row<3;++row)
        for(int col=0; col<3;++col)
            if(grid[row+startrow][col+startcol] == num)
                return true;
    return false;
}

bool sudoku::isSafe(int row, int col, int num){
    if( !UsedInRow(row, num) &&
        !UsedInCol(col, num) &&
        !UsedInBox(row - row%3, col-col%3, num))
        return true;
    return false;

}

void sudoku::printBoard(){
    for(int row=0;row<9;++row){
        for(int col=0;col<9;++col)
            cout<<grid[row][col]<<" ";
        cout<<"\n";
    }
}

void sudoku::printFancyBoard(){
    cout<<"\n";
    for(int row=0;row<9;++row){
        for(int col=0;col<9;++col){
            cout<<grid[row][col]<<" ";
            if((row==2 || row == 5) && col==8)
                cout<<"\n------ ------- ------";
            if(col == 2 || col == 5)
                cout<<"| ";
        }
        cout<<"\n";
    }
}

int main(){
    int t,no;
    vector<vector<int> > grid(9, vector<int>(9,0));
    cin>>t;
    while(t--){
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                cin>>grid[i][j];
        sudoku s(grid);
        if(s.solveSudoku())
            s.printBoard();
    }
}