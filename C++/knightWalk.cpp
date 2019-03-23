#include<iostream>
#include<vector>
using namespace std;

class knightWalk{

    vector<vector<int>> board;
    int destinationX, destinationY;
    int path = 0;

    public:
    knightWalk(int M,int N, int dx, int dy){
        board = vector<int>(N, vector<int>(M,0));
        destinationX = dx;
        destinationY = dy;
    }

    int findMinPath(int sx, int sy, int N, int M);
    bool canMove(int x, int y, int N, int M);
    
};

bool knightWalk::isDestinaiton(int x, int y){
    if(x == destinationX && y == destinationY)
        return true;
    return false;
}

int knightWalk::findMinPath(int row, int column, int N, int M){
    
    int path1=0, path2=0, path3=0, path4=0, path5=0, path6=0, path7=0, path8=0;

    if(row == destinationX && column == destinationY)
        return 0;
    
    board[row][col] = path++;
    
    if (canMove(row + 2, column + 1, N, M)){
		path1 += findPath(row + 2, column + 1, N, M);
        if(path1 == -1)
            return -1;
	}
		// go right and down
	if (canMove(row + 1, column + 2, N, M)){
        path2 += findPath(row + 1, column + 2, N, M);
        if(path2 == -1)
            return -1;
    }
		
		// go right and up
	if (canMove(row - 1, column + 2, N), M){
        path3 += findPath(row - 1, column + 2, N, M);
        if(path3 == -1)
            return -1;
    }
		// go up and right
	if (canMove(row - 2, column + 1, N, M)){
        path4 += findPath(row - 2, column + 1, N, M);
        if(path4 == -1)
            return -1;
    }

		// go up and left
	if (canMove(row - 2, column - 1, N, M)){
        path5 += findPath(row - 2, column - 1, N, M);
        if(path5 == -1)
            return -1;
    }

		// go left and up
	if (canMove(row - 1, column - 2, N, M)){
        path6 += findPath(row - 1, column - 2, N, M);
        if(path6 == -1)
          return -1;  
    }
				
		// go left and down
	if (canMove(row + 1, column - 2, N, M)){
        path7 += findPath(row + 1, column - 2, N, M);
        if(path7 == -1)
            return -1;
    }
				
		// go down and left
	if (canMove(row + 2, column - 1, N, M)){
        path8 += findPath(row + 2, column - 1, N, M);
        if(path8 == -1)
            return -1;
    }

    

}

bool knightWalk::canMove(int row, int col, int N, int M){
    if(row>=0 && row<N && col>=0 && col<M)
        return true;
    return false;
}