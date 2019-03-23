//Given 2 strings of 0's and 1's. perform addition from right to left
#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#include<string>
using namespace std;

#define r_all(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end();

/*
struct number{
    vector<int> vec;

    number() {};
    number(string n){
        transform(r_all(n), back_inserter(vec), [=](char c){ return c - '0'; });
    } 

    inline int operator[](int idx){
        if(idx < 0 || idx >= vec.size())
            throe runtime_error("Out of bounds\n");
        return vec[idx];
    }

    number operator+(number &other){
        int carry = 0;
        int idx = 0;
        vector<int> result;
        do{
            if(idx < size())
                carry += vec[idx];
            if(idx < other.size())
                carry += other.vec[idx];
            result.push_back(carry%10);
            carry /= 10;
            ++idx;
        } while(carry != 0 || idx < size() || idx < other.size());
        return result;
    }

    inline auto begin() { return vec.begin(); }
    inline auto end() { return vec.end(); }
    inline auto rbegin() { return vec.r_begin(); }
    inline auto rend() { return vec.r_end(); }

};

bool valid(int c){
    return c == 0 || c == 1;
}

friend istream& operator>>(istream &is, number &obj){
    string a;
    is >> a;
    bool valid_ints = accumulate(all(a), true, [=](bool init, int c){
        return init && valid(c);
    });
    if(valid_ints)
        obj = a;
    else   
        throw runtime_error("Invalid number, enter only 0's and 1's\n");
    return is;
}
*/

void add(vector<int> a1, vector<int> b1){
    int carry = 0;
    vector<int> vec;
    int idx = 0;
    do{
        if(idx < a1.size())
            carry += a1[idx];
        if(idx < b1.size())
            carry += b1[idx];
        
        vec.push_back(carry%10);
        carry /= 10;
        ++idx;
    } while(carry != 0 || idx < a1.size() || idx < b1.size());
    for(int i=0;i<vec.size();++i)
        cout<<vec[i];
    cout<<"\n";
}

int main(){
    string a, b;
    vector<int> a1, b1;
    cin>>a>>b;
    transform(r_all(a), back_inserter(a1), [=](char c){ return c - '0';});    
    transform(r_all(b), back_inserter(b1), [=](char c){ return c - '0';});
    add(a1, b1);
}