//Program to add N bit numbers
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
#include<numeric>
using namespace std;
/*
int character(char c){
    return c - '0';
}

void print(vector<int> vec){
    for(int i = vec.size()-1; i>=0;i--)
        cout<<vec[i];
    cout<<"\n";
}

void add(vector<int> a1, vector<int> b1){
    vector<int> vec;
    int sum, carry = 0;
    int len = a1.size() > b1.size() ? a1.size() : b1.size();
    for(int i=0;i<len;++i){
        sum = a1[i] + b1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        vec.push_back(sum);
    }
    if(carry != 0)
        vec.push_back(carry);
    print(vec);
}

int main(){
    string a, b;
    cin>>a>>b;
    vector<int> a1, b1;
    transform(a.rbegin(), a.rend(), back_inserter(a1), character);
    transform(b.rbegin(), b.rend(), back_inserter(b1), character);
    add(a1, b1);
}*/


#define all(v) v.begin(), v.end()
#define r_all(v) v.r_begin(), v.r_end()

struct var_int{
    vector<int> number;

    var_int(){}
    var_int(vector<int> number) : number(number) {}
    var_int(string str_number){
        transform(r_all(str_number), back_inserter(number), [=](char c){ return c - 48; });
    }

    inline int& operator[](int idx){
        if(idx < 0 || idx >= number.size())
            throw runtime_error("Out of bounds\n");
        return number[idx];
    }

    var_int operator+(const var_int &other){
        int carry = 0;
        int idx = 0;
        vector<int> result;
        do{
            if(idx < size())
                carry += number[idx];
            if(idx < other.size())
                carry += other.number[idx];
            
            result.push_back(carry%10);
            carry /= 10;
            idx++;
        } while(carry != 0 || idx < size() || idx < other.size());
        return result;
    }

    inline decltype(auto) begin() { return number.begin(); }
    inline decltype(auto) end() { return number.end(); }
    inline decltype(auto) rbegin() { return number.rbegin(); }
    inline decltype(auto) rend() { return number.rend(); }

    inline size_t size() const{ return number.size(); }

    friend istream& operator>>(istream &is, var_int &obj);
    friend ostream& operator<<(istream &os, const var_int &obj);

    inline bool valid(char c){ 
        return (c > 48 && c < 57); 
    }

    friend istream& operator>>(istream &is, var_int &obj){
        string number;
        is>>number;
        bool valid_ints = accumulate(all(number), true, [=](bool init, char c){ 
            return init && valid(c); 
        });
        if(valid_ints)
            obj = number;
        else
            throw runtime_error("Invalid number, must contain digits only\n");
        
        return is;
    }

    friend ostream& operator<<(ostream &os, const var_int &obj){
        for_each(all(obj.number), [&](int c){ os << c; });
        return os;
    }
};

int main(){
    var_int n1, n2;
    cin>>n1>>n2;
    cout<<n1 + n2;
}