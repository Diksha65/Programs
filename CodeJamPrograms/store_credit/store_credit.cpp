#include <iostream>
#include <vector>
#include <utility>
using namespace std;
/*
void display(pair<int, int> p, int count){
    cout<<"Case #"<<count<<": "<<p.first<<" "<<p.second<<"\n";
}
*/
void print(){}
template<class T, class... Types>
void print(const T &first, const Types&... va_list){
	cout<<first<<" ";
	print(va_list...);
}

template<class... T>
void print_case(int count, const T&... va_list){
	cout<<"Case#"<<count<<": ";
	print(va_list...);
	cout<<"\n";
}


pair<int, int> store_credit(int credit, int no_items){
    int item;
    vector<int> items(no_items, 0);
    for(int i = 0; i < no_items; ++i){
		cin>>item;
        items[i]=item;
    }
	for(int i=0;i<no_items;++i){
        for(int j=i+1; j<no_items; ++j)
            if( ( items[i] + items[j] ) == credit )
                return make_pair(i+1 , j+1);
    }
}

int main(){
    int no_cases, no_items, credit, count=1;
    pair<int, int> indexes;
    cin>>no_cases;
    while(no_cases>0){
        cin>>credit;
        cin>>no_items;
        indexes=store_credit(credit, no_items);
		//display(indexes, count);
		print_case(count, indexes.first, indexes.second);
        count += 1; no_cases -= 1;
    }
}
