#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef unsigned char uchar;

int main(){
	//initialize cache and user input
	int n, m , q;
	cin >> n >> m >> q;
	uchar* cache = new uchar[n];
	fill(cache, cache+n, 0);

	//populate memory
	vector<vector<uchar>> memory;
	memory.reserve(m);
	int size;
	for(int i = 0; i < m; i++){
		cin >> size;
		vector<uchar> memLine;
		memLine.reserve(size);
		int input;
		for(int j = 0; j < size; j++){
			cin >> input;
			memLine.emplace_back(input);
		}
		memory.emplace_back(memLine);
	}

	//main simulation
	for(int instr = 0; instr < q; instr++){
		int instruction;
		cin >> instruction;
		switch(instruction){
			//load
			case 1:{
				int i, p;
				cin >> i >> p;
				i--;p--;
				for(int x = 0; x < memory[i].size(); x++){
					cache[p++] = memory[i][x];
				}
				break;
			}
			//print
			case 2:{
				int p;
				cin >> p;
				cout << int(cache[p-1]) << endl;
				break;
			}
			//increment range
			case 3:{
				int i,l,r;
				cin >> i >> l >> r;
				i--;
				for(int x = l-1; x < r; x++){
					memory[i][x]++;
				}
				break;
			}
		}
	}
	return 0;
}