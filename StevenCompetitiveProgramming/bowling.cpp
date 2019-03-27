#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

string formatString(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

int calculateFinalRoundSum(string str, int j){
    int sum = 10;
    if(str[j+2] == '/')
        sum += 10;
    else if(str[j+1] == 'X')
        sum += 10 + str[j+2] - '0';
    else if(str[j+1] == 'X' && str[j+2] == 'X')
        sum += 20;
    else
        sum += str[j+1] + str[j+2] - (2*'0');
}

int calculateStrikeSum(string str, int j){
    int sum = 10;
    if(str[j+1] == 'X' && str[j+2] == 'X')
        sum += 20;
    else if(str[j+1] == 'X')
        sum += 10 + str[j+2] - '0';
    else if(str[j+2] == '/')
        sum += 10;
    else
        sum += str[j+1] + str[j+2] - (2*'0');
    return sum;
}

int calculateSpareSum(string str, int j){
    int sum = 10;
    if(str[j+1] == 'X')
        sum += 10;
    else
        sum += str[j+1] - '0';
    return sum;
}

void display(vector<int> vec){
    for(int i=0;i<vec.size();++i)
        cout<<vec[i]<<"\t";
    cout<<"\n";
}

int calculateScore(string str){
    vector<int> sums;
    int i=1, j=0, sum=0; 
    while(i<=10){
        if(i == 10 && str[j] == 'X')
            sum = calculateFinalRoundSum(str,j);
        if(str[j] == 'X'){
            sum = calculateStrikeSum(str,j);
            j += 1;
        }
        else if(str[j+1] == '/'){
            sum = calculateSpareSum(str, j+1);
            j += 2;
        }
        else{
            sum = str[j]+str[j+1] - (2*'0');
            j += 2;
        }     
        sums.push_back(sum);
        i += 1;
    }
    sum = accumulate(sums.begin(), sums.end(), 0);
    return sum;
}

int main(){
    string str;
    int n;
    ofstream out; ifstream in;
    out.open("output.txt"); in.open("input.txt");
    
    while(getline(in, str)){
        if(str == "Game Over")
            break;
        else{
            str = formatString(str);
            int n = calculateScore(str);
            out<<n<<"\n";
        }
    }

    out.close(); in.close();
}