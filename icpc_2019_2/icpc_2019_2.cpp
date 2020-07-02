#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//removes useless characters
string encode(string s){
	string tmp = "";
	for(char c : s){
		if(c >= 'a' && c <= 'z') tmp.push_back( (c-32) );
		else if(c >= 'A' && c <= 'Z') tmp.push_back(c);
	}
	return tmp;
}

//populates direct address table of letter counts
void count(int* dat, string s){
	for(char c : s){
		dat[c-'A']++;
	}
}

int main(){
	//get input
	string message;
	getline(cin,message);
	message = encode(message);
	if(message.size() == 0){
		cout << 0 << endl;
		return 0;
	}

	//setup direct address tables
	int score[] = {1,3,3,5,5,7,7,7,7,9,9,9,11,11,11,11,11,11,13,13,13,13,15,15,15,15};
	int dat[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	count(dat, message);

	//main algorithm
	sort(dat,dat+26);
	int index = 0;
	while(dat[index] == 0) index++;

	int result = 0, scoreIndex = 26 - index -1;
	while(index < 26){
		result += dat[index++] * score[scoreIndex--];
	}
	result += (message.size()-1) * 3;

	//print result
	cout << result << endl;
	return 0;
}