#include<iostream>
#include<vector>
using namespace std;
/*
vector<vector<int> > moves = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};

bool isSafe(int x, int y, vector<vector<int> > board){
    if(x<0 || x>board.size()-1 ||
        y<0 || y>board.size()-1 ||
            board[x][y] != 0)
                return false;
    return true;
}

void printBoard(vector<vector<int> > board){
    for(int i=0;i<board.size(); ++i){
        for(int j=0;j<board[i].size(); ++j){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool placeKnights(vector<vector<int> >board, int x, int y, int k, int max_moves){
    if(k>=max_moves)
        printBoard(board);
    
    for(int i=0;i<moves.size(); ++i){
        int newRow = x+moves[i][0];
        int newCol = x+moves[1][i];
        if(isSafe(newRow, newCol, board)){
            board[newRow][newCol] = k;
            if(placeKnights(board, newRow, newCol, k+1, max_moves))
                return true;
            else
                board[newRow][newCol] = 0;
        }
    }
    printBoard(board);
    return false;
}

int main(){
    int m,n,x,y,k;
    cout<<"Enter size of the board:\n";
    cin>>m>>n;
    vector<vector<int> > board(m, vector<int> (n, 0));
    cout<<"Enter the x and y coordinate of the location of the knight:";
    cin>>x>>y;
    printBoard(board);
    k=m*n;
    cout<<m<<n<<x<<y<<k;
    if(placeKnights(board, x, y, 0, k))
        cout<<"\nThe knight has a closed tour\n";
    else   
        cout<<"\nThe knight does not have a closed tour\n";
}
*/


class knightsTour{
    vector<vector<int> > board;
    vector<vector<int> > moves;
    int path;

    public:
    knightsTour(int N){
        path = 0;
        board = vector<vector<int> >(N, vector<int> (N, 0));
        moves = {{2,1},{2,-1},{1,2},{1,-2},{-2,1},{-2,-1},{-1,2},{-1,-2}};
    }

    void solve();
    void printBoard();
    bool findPath(int row, int col, int index, int N);
    bool canMove(int row, int col, int N);
};

void knightsTour::solve(){
    if(findPath(0,0,0,board.size()))
        printBoard();
    else    
        cout<<"No path found\n";
}

void knightsTour::printBoard(){
    for(int i=0;i<board.size();++i){
        for(int j=0;j<board.size();++j){
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

bool knightsTour::canMove(int row, int col, int N){
    if(row>=0 && row<N && col>=0 && col<N)
        return true;
    return false;
}

bool knightsTour::findPath(int row, int col, int index, int N){
    if(board[row][col] != 0)
        return false;
    
    board[row][col] = path++;
    if(index == N*N -1)
        return true;
    
    if(canMove(row+2, col+1, N) && findPath(row+2, col+1, index+1, N))
        return true;
    
    if(canMove(row+2, col-1, N) && findPath(row+2, col-1, index+1, N))
        return true;
    
    if(canMove(row+1, col-2, N) && findPath(row+1, col-2, index+1, N))
        return true;
    
    if(canMove(row-1, col-2, N) && findPath(row-1, col-2, index+1, N))
        return true;
    
    if(canMove(row-2, col-1, N) && findPath(row-2, col-1, index+1, N))
        return true;
    
    if(canMove(row-2, col+1, N) && findPath(row-2, col+1, index+1, N))
        return true;
    
    if(canMove(row+1, col+2, N) && findPath(row+1, col+2, index+1, N))
        return true;
    
    if(canMove(row-1, col+2, N) && findPath(row+1, col+2, index+1, N))
        return true;

    board[row][col] = 0;
    path--;
    return false;
}

int main(){
    int N = 4;
    knightsTour ktour(N);
    ktour.solve();
}