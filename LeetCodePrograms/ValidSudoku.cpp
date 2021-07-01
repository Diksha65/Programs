//Question
//https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/769/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<string>>& board) {
    unordered_set<string> s;
    
    //Checking horizontally
    for(int i = 0; i<9 ; i++) {
        s.clear();
        for(int j=0;j<9; j++) {
            if(board[i][j] != ".") {
                if (s.count(board[i][j]) == 1) {
                    return false;
                }
                s.insert(board[i][j]);
            }
        }
    }
    
    //Checking vectically
    for(int i = 0; i<9 ; i++) {
        s.clear();
        for(int j=0;j<9; j++) {
            if(board[j][i] != ".") {
                if (s.count(board[j][i]) == 1) {
                    return false;
                }
                s.insert(board[j][i]);
            }
        }
    }
    
    //Checking box wise
    for(int i= 0; i<9 ; i=i+3) {
        for(int j=0;j<9; j=j+3) {
            
            s.clear();
            for(int k=i;k<i+3;k++) {
                for(int l=j;l<j+3;l++) {
                    
                    if(board[k][l] != ".") {
                        if (s.count(board[k][l]) == 1) {
                            return false;
                        }
                        s.insert(board[k][l]);
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<string> > vec {
        {"5","3",".",".","7",".",".",".","."},
        {"6",".",".","1","9","5",".",".","."},
        {".","9","8",".",".",".",".","6","."},
        {"8",".",".",".","6",".",".",".","3"},
        {"4",".",".","8",".","3",".",".","1"},
        {"7",".",".",".","2",".",".",".","6"},
        {".","6",".",".",".",".","2","8","."},
        {".",".",".","4","1","9",".",".","5"},
        {".",".",".",".","8",".",".","7","9"}};
    cout<<isValidSudoku(vec);
    return 0;
}