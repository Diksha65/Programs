#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;

void print(){ cout<<"\n"; }
template<class T, class... Types>
void print(const T &first, const Types&... va_list){
    cout << first << " ";
    print(va_list...);
}

struct item{
    int index;
    int credit;
    bool operator<(const item &other){
        return credit < other.credit;
    }
    bool operator==(const item &other){
        return (credit == other.credit) &&
                (index != other.index);
    }
};
int main(){
    int n;
    cin >> n;
    int case_number = 0;
    const string case_print="Case#";
    while(n > 0){
        int credit, number, input;
        cin >> credit >> number;
        vector<item>values(number);
        vector<item>cmp_values(number);

        for(int index = 0; index < number; ++index){
            cin >> input;
            cmp_values[index].index  = index;
            cmp_values[index].credit = credit - input;
            values[index].index  = index;
            values[index].credit = input;
        }

        sort(all(cmp_values));
        
        
        for(int i = 0; i < number; ++i){
            auto pos = lower_bound(all(cmp_values), values[i]);
            if(pos != cmp_values.end() &&
                *pos == values[i]){
                
                ++case_number;

                int low = pos->index, 
                    high= values[i].index;
                if(low > high)
                    swap(low, high);

                print(case_print, case_number, ":", low + 1, high + 1);
                
                break;
            }
        }
        --n;
    }
}