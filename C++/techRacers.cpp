#include<iostream>
#include<vector>
using namespace std;

class FindPath{
    int vertices;
    vector<vector<int> > grid;
    vector<int> vec;

    public:
    FindPath(vector<vector<int> > g, int N){
        grid = g;
        vertices = N;
    }

    bool canMove(int row, int col);
    bool findPath(int row, int col);
};

bool FindPath::canMove(int row, int col){
    return row>=0 && row<vertices && 
            col >=0 && col<vertices &&
            grid[row][col] == 1
}

bool FindPath::findPath(int row, int col){
    if(row == grid.size()-1 && 
        col == grid.size()-1 && 
        grid[row][col] == 1)
        return true;

}


int main(){
    vector<vector<int> > grid = {{1, 1, 1, 1},
                                 {1, 0, 1, 1}, 
                                 {1, 0, 1, 1},
                                 {1, 1, 1, 1}};
    FindPath f(grid, 4);
    f.findPath(0, 0);
}