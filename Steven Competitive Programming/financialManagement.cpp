#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

string formatOutput(double average){
    string num = to_string(average);
    int decimal = num.find('.');
    int insert_position = num.length() - decimal - 3;
    while(insert_position > 0){
        num.insert(insert_position, ",");
        insert_position -= 3;
    }
}

int main(){
    int sets;
    double amount, sum, average;
    cin>>sets;
    for(int j=1;j<=sets;++j){
        sum = 0;
        for(int i=0;i<12;++i){
            cin>>amount;
            sum += amount;
        }
        average = sum / 12;
        string n = formatOutput(average);
        cout<<j<<" $"<<setprecision(2)<<fixed<<n<<"\n";
    }
}