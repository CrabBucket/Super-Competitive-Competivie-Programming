#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

double slope(int x1, int x2, int y1, int y2){
	return ((double)(y2-y1)) / ((double)(x2-x1));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//get input
	vector<int> points;
	int x;
	cin >> x;
	while(!cin.eof()){
		points.push_back(x);
		cin >> x;
	}

	//create direct address table
	int* dat = new int[points.size()];
	fill(dat,dat+points.size(),0);

	//main algorithm
	for(int i = 0; i < points.size()-1; i++){
		double baseSlope = slope(i, i+1, points[i], points[i+1]);
		dat[i]++; dat[i+1]++; 
		for(int j = i+2; j < points.size(); j++){
			double newSlope = slope(i, j, points[i], points[j]);
			if(newSlope >= baseSlope){
				dat[i]++; dat[j]++;
				baseSlope = newSlope;
			}
		}
	}

	//get min max
	int max = -1000, maxIndex = -1, min = INT_MAX, minIndex = -1;
	for(int i = 0; i < points.size(); i++){
		if(dat[i] > max){
			max = dat[i];
			maxIndex = i;
		}
		if(dat[i] < min){
			min = dat[i];
			minIndex = i;
		}
	}

	//print results
	cout << maxIndex << ' ' << max << '\n'
		 << minIndex << ' ' << min << '\n';
	return 0;
}