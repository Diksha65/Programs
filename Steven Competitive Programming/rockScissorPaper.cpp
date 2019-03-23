#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

char winner(const vector<vector<char> > vec, int i, int j, char w){
    if( (j+1 < vec[0].size() && vec[i][j+1] == w) ||
        (j-1 > 0 && vec[i][j-1] == w) ||
        (i-1 > 0 && vec[i-1][j] == w) ||
        (i+1 < vec.size() && vec[i+1][j] == w))
        return w;
    return vec[i][j];
}

char findWinner(const vector<vector<char> > vec, char a, int i, int j){
    if(a == 'R')
        return winner(vec, i,j,'P');
    if(a == 'P')
        return winner(vec, i,j,'S');
    if(a == 'S')
        return winner(vec, i,j, 'R');
}

vector<vector<char> > afterWar(vector<vector<char> > today, int n, int row, int col){
    vector<vector<char> > tom(row, vector<char>(col,0));
    for(int i=1 ; i<=n ; ++i){
        for(int j=0;j<row;++j)
            for(int k=0;k<col;++k)
                tom[j][k] = findWinner(today, today[j][k], j,k);
        today = tom;
    }
    return today;
}


void display(vector<vector<char> > today, int row, int col){
    for(int i=0;i<row; ++i){
        for(int j=0;j<col;++j)
            cout<<today[i][j];
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){
    int nocases;
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    int r,c,n;
    string str;
    cin>>nocases;
    for(int i=0;i<nocases;++i){
        cin>>r>>c>>n;
        vector<vector<char> > today(r, vector<char>(c,0));
        if(r == 0 && c == 0){ 
            cout<<"\n";
            continue;
        } else if(r == 1 && c == 1){
            cin>>str; cout<<str<<"\n";
            continue;
        } else {
            for(int j=0;j<r;++j){
                cin>>str;
                for(int k=0;k<c; ++k)
                    today[j][k] = str[k];
            }
            display(today, r, c);
            today = afterWar(today,n,r,c);
            display(today, r, c);
        }
    }

    out.close(); in.close();
}