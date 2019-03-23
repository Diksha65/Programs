/*#include<iostream>
#include<vector>
using namespace std;

void print(vector<vector<bool> > visited){
    for(int i=0;i<visited.size();++i){
        for(int j=0;j<visited[i].size();++j){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
}


bool isSafe(vector<vector<int> > grid, int row, int col, vector<vector<bool> > visited){
    return (row>=0) && (col>=0) &&
        (row < grid.size()) && (col < grid[0].size()) &&
        (grid[row][col]==1 && !visited[row][col]);

}

void DFS(vector<vector<int> > grid, int row, int col, vector<vector<bool> > visited, int &count){

    int r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int c[] = {-1, 0, 1, -1, 1, -1, 0, -1};

    visited[row][col] = true;
    for(int k=0;k<8;++k){
        if(isSafe(grid, row+r[k], col+c[k], visited)){
            count += 1;
            DFS(grid, row+r[k], col+c[k], visited, count);
        }
    }
}

int largest(vector<vector<int> > grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int result = -1, count;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j] && !visited[i][j]){
                count = 1;
                DFS(grid, i, j, visited, count);
                result = result>count ? result : count;
            }
        }
    }
    return result;
}

int main(){
    int t, n, m, no;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int> > grid(n, vector<int>(m,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>grid[i][j];
        cout<<largest(grid)<<"\n";
    }
}*/

#include<bits/stdc++.h>
using namespace std;
// A function to check if a given cell (row, col)
// can be included in DFS
int isSafe(vector<vector<int> > M, int row, int col,
           vector<vector<bool> > visited)
{
    // row number is in range, column number is in
    // range and value is 1 and not yet visited
    return (row >= 0) && (row < M.size()) &&
           (col >= 0) && (col < M[0].size()) &&
           (M[row][col] && !visited[row][col]);
}
 
// A utility function to do DFS for a 2D boolean
// matrix. It only considers the 8 neighbours as
// adjacent vertices
void DFS(vector<vector<int> > M, int row, int col,
         vector<vector<bool> > visited, int &count)
{
    // These arrays are used to get row and column
    // numbers of 8 neighbours of a given cell
    static int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
    // Mark this cell as visited
    visited[row][col] = true;
 
    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
    {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],
                                              visited))
        {
            // increment region length by one
            count++;
            DFS(M, row + rowNbr[k], col + colNbr[k],
                                    visited, count);
        }
    }
}
 
// The main function that returns largest  length region
// of a given boolean 2D matrix
int  largest(vector<vector<int> > M)
{
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    //bool visited[ROW][COL];
    //memset(visited, 0, sizeof(visited));
    vector<vector<bool> > visited(M.size(), vector<bool>(M[0].size(), false));
    // Initialize result as 0 and travesle through the
    // all cells of given matrix
    int result  = INT_MIN;
    for (int i = 0; i < M.size(); ++i)
    {
        for (int j = 0; j < M[0].size(); ++j)
        {
            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j])
            {
                // visited yet, then new region found
                int count = 1 ;
                DFS(M, i, j, visited , count);
 
                // maximum region
                result = max(result , count);
            }
         }
    }
    return result ;
}
 
// Driver program to test above function
int main()
{
    int t, n, m, no;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int> > grid(n, vector<int>(m,0));
        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>grid[i][j];
        cout<<largest(grid)<<"\n";
    }
}
