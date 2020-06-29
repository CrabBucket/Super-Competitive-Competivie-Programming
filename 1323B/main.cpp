#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <map>

using namespace std;
typedef unsigned long long ull;

//divisors calculator O(sqrt(n))
vector<int> getDivisors(int n){
	vector<int> divisors;
    int i = 1;
    while(i < (int) ceil(sqrt(n))){ 
        if(n % i==0) {
        	divisors.push_back(i);
        	divisors.push_back(n / i);
        }
        i++;
    }
    if((int) sqrt(n) == sqrt(n))
    	divisors.push_back(sqrt(n));
    return divisors;
}

//reads in n input digits and places size of consecutive 1's into a map
void contigCount(map<int, int>& m, int n){
	int count = 0, temp;
	while(n--){
		cin >> temp;
		if(temp)
			count++;
		else{
			if(count){
				if(m.count(count) == 0)
					m[count] = 1;
				else
					m[count]++;
				count = 0;
			}
		}
	}
	if(count){
		if(m.count(count) == 0)
			m[count] = 1;
		else
			m[count]++;
	}
}

//Gets all rectangles that can be formed with size n
vector<pair<int, int>> getRects(int n){
	vector<pair<int, int>> rects;
	vector<int> divs = getDivisors(n);
    for(int div : divs)
        rects.push_back(make_pair(div, n / div));
    return rects;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	ull total = 0;

	int n, m, size;
	cin >> n >> m >> size;

	vector<pair<int,int>> sizeRects = getRects(size);
	
	map<int, int> contigA, contigB;
	contigCount(contigA, n);
	contigCount(contigB, m);

	map<int,int>::iterator it, jt;
	for(it = contigA.begin(); it != contigA.end(); it++){
		for(jt = contigB.begin(); jt != contigB.end(); jt++){
			for(pair<int,int> s : sizeRects)
				if (it->first >= s.first and jt->first >= s.second)
					total += (ull)(it->first - s.first + 1) * (ull)(jt->first - s.second + 1) * it->second * jt->second;
		}
	}

	cout << total;
	return 0;
}