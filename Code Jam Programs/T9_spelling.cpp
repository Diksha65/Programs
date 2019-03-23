#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find_sequence(string text, vector<string> letters, int c_no){
	cout<<"Case #"<<c_no<<": ";
	int np,c, index;
	vector<int> vec(text.size(), 0);
	for(int i=0; i<text.size(); ++i){
		if(text[i] == ' '){
			vec[i] = 0;
			if(vec[i] == vec[i-1])
				cout<<" ";
			cout<<"0";
			continue;
		}
		np=int(text[i])-97;
		if(np<15){
			index=(np/3)+2;
			vec[i]=index;
			if(vec[i] == vec[i-1])
					cout<<" ";
			for(int k=0;k<letters[index].size();++k)
				if(letters[index][k] == text[i])
					c=k+1;
			for(int k=0;k<c;++k)
				cout<<index;
		}
		if(np>=15){
			np += 1;
			if(np == 23){
				index = 9;
				vec[i]=index;
			}
			else{
				index = (np/4) + 3;
				vec[i]= index;
			}
			if(vec[i] == vec[i-1])
				cout<<" ";
			for(int k=0;k<letters[index].size(); ++k)
				if(letters[index][k] == text[i])
					c=k+1;
			for(int k=0;k<c;++k)
				cout<<index;
		}
	}
	cout<<"\n";
}

int main(){
	vector<string> letters(10, " ");
	letters[0] = " ";
	letters[1] = "";
	letters[2] = "abc";
	letters[3] = "def";
	letters[4] = "ghi";
	letters[5] = "jkl";
	letters[6] = "mno";
	letters[7] = "pqrs";
	letters[8] = "tuv";
	letters[9] = "wxyz";
	int cases, case_number=1;
	string text, extra;
	cin>>cases;
	getline(cin, extra);
	for(int i=0;i<cases; ++i){
		getline(cin, text);
		find_sequence(text, letters, case_number);
		case_number += 1;
	}
}