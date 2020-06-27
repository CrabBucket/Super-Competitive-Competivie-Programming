#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	int desks[k];
	for(int i = 0; i < k; i++){
		cin >> desks[i];
	}

	int ptr = 0, last = 0, count = 1;
	while(ptr < k){
		if(desks[ptr] > last){
			last = desks[ptr];
			ptr++;
		}
		else{
			count++;
			last = 0;
		}
	}

	cout << count;

	return 0;
}