#include<iostream>
using namespace std;

int count = 0;
void moveSingleDisk(char start, char finish){
    count += 1;
    cout<<start<<" -> "<<finish<<endl;
}

void moveTower(int n, char start, char finish, char temp){
    if(n == 1)
        moveSingleDisk(start, finish);
    else {
        moveTower(n-1, start, temp, finish);
        moveSingleDisk(start, finish);
        moveTower(n-1, temp, finish, start);
    }
}

int main(){
    moveTower(5, 'A', 'B', 'C');
    cout<<count<<"\n";
}