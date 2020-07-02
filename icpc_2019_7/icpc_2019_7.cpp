#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

double max(double a, double b){
	return (a > b) ? a : b;
}

double greatestDifference(double* arr, int size){
	return arr[size-1] - arr[0];
}

int main(){
	//initial input
	int flaws;
	cin >> flaws;

	double* x = new double[flaws];
	double* y = new double[flaws];
	double* z = new double[flaws];
	for(int i = 0; i < flaws; i++){
		cin >> x[i] >> y[i] >> z[i];
	}

	//main algorithm
	sort(x, x+flaws);
	sort(y, y+flaws);
	sort(z, z+flaws);
	double tmp[] = {
		greatestDifference(x,flaws),
		greatestDifference(y,flaws),
		greatestDifference(z,flaws)
	};

	//print result
	sort(tmp,tmp+3);
	printf("%.10f\n", tmp[1]);
}