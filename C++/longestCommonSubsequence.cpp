#include<iostream>
#include<vector>
using namespace std;

void lcs_length(vector<char> X, vector<char> Y, 
    vector<vector<char> > &b, vector<vector<int> > &c){
    int m = X.size();
    int n = Y.size();

    for(int i=1; i<=m; i++){
        for(int j=1;j<=n;j++){
            if(X[i-1] == Y[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '\\';
            } else if(c[i-1][j] > c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            } else {
                c[i][j] = c[i][j-1];
                b[i][j] = '-';
            }
        }
    }
}

void print_lcs(vector<vector<char> > b, vector<char> X, int i, int j){
    if(i == 0 && j == 0)
        return;
    if(b[i][j] == '\\'){
        print_lcs(b, X, i-1, j-1);
        cout<<X[i-1];
    } else if(b[i][j] == '|')
        print_lcs(b, X, i-1, j);
    else 
        print_lcs(b, X, i, j-1);
}

int main(){
    vector<char> X = {'A','B','C','B','D','A','B'};
    vector<char> Y = {'B','D','C','A','B','A'};
    int n = Y.size();
    int m = X.size();
    vector<vector<char> > b(m+1, vector<char>(n+1, ' '));
    vector<vector<int> > c(m+1, vector<int>(n+1, 0));
    lcs_length(X, Y, b, c);
    print_lcs(b, X, n-1, m-1);
}




