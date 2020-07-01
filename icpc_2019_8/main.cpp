#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//input
	int k;
	cin >> k;
	int desks[k];
	for(int i = 0; i < k; i++){
		cin >> desks[i];
	}

	//ptr is the index value for desks
	//last marks the number of the last desk
	//count keeps track of how many times you must go through the line
	int ptr = 0, last = 0, count = 1;
	while(ptr < k){
		//ok to get signature
		if(desks[ptr] > last){
			last = desks[ptr];
			ptr++;
		}
		//need to "go back to end of line"
		else{
			count++;
			last = 0;
		}
	}

	cout << count;

	return 0;
}