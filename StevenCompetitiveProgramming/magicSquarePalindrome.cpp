#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;

bool checkCharacter(char c){
    if(isalpha(c))
        return false;
    else
        return true;
}

string formatString(string str){
    str.erase(remove_if(str.begin(), str.end(), checkCharacter), str.end());
    return str;
}

vector<vector<char> > createMatrix(string str){
    int len = str.size();
    int lenHalf = sqrt(len);
    int k=0;
    vector<vector<char> > vec(lenHalf, vector<char>(lenHalf,0));
    for(int i=0 ; i<lenHalf; ++i)
        for(int j=0 ; j<lenHalf ; ++j)
            vec[i][j] = str[k++];
    return vec;
}

int checkPalindrome(vector< vector<char> > vec){
    if(vec.size() == 0) return 0;
    if(vec.size() == 1) return 1;

    int i,j, k=vec.size()-1, l, flag = -1;
    for(i=0;i<vec.size();++i, --k)
        for(j=i+1, l=k-1;j<vec.size();++j, --l)
            if((vec[i][j] == vec[j][i]) && (vec[j][i] == vec[k][l]) && (vec[k][l] == vec[l][k]))
                flag = vec.size();
    return flag;

}

int main(){
    int no_cases;
    string str, extra;
    vector<vector<char> > mat;
    ifstream in; ofstream out;
    in.open("input.txt"); out.open("output.txt");
    int n;
    in>>no_cases;
    in.ignore();
    for(int i=0;i<no_cases;++i){
        getline(in, str);
        str = formatString(str);
        mat = createMatrix(str);
        int n = checkPalindrome(mat);
        out<<"Case #"<<i+1<<":\n";
        if(n != -1)
            out<<n<<"\n";
        else 
            out<<"No magic :(\n";
    }

    out.close(); in.close();
}