#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
vector<string> create_vector(const int words,const int letters){
	vector<string> allowed_words(words, " ");
	string entry;
	for(int i=0; i<words; ++i){
		cin>>entry;
		if(entry.size() == letters){
			allowed_words[i] = entry;
		}
		cout<<allowed_words[i]<<"\n";
	}
	return allowed_words;
}
*/

int find_word(const vector<string> al_words, int letters){
	int count=0;
	string str, str1[letters];
	cin>>str;
	for(int i=0;i<str.size();++i){
		if(str[i] != "(" && str[i] != ")"){
			str1[i] = str[i];
		}
	}




	int *p = find(al_words.begin(), al_words.end(), str1);
	if(p!=al_words.end())
		return count;
}

/*
void display(int count, int case_number){
	cout<<"Case #"<<case_number<<": "<<count;
}

int main(){
	int letters, words, cases, case_number=1;
	cin>>letters>>words>>cases;
	for(int i=0;i<cases;++i){
		int count=find_word(create_vector(words, letters), letters);
		display(count, case_number);
		case_number += 1;
	}
}
*/
tf