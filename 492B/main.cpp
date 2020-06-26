/*
0 3 5 7 9 14 15
        ---
         5
         5/2 = 2.5

ends of streets are special cases
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;
	int lights[n];
	for(int i = 0; i < n; i++){
		cin >> lights[i];
	}
	
	sort(lights, lights+n);
	int greatestDist = 0;
	for(int i = 1; i < n; i++){
		if(lights[i] - lights[i-1] > greatestDist){
			greatestDist = lights[i] - lights[i-1];
		}
	}

	double d = greatestDist / 2.0;

	//check edge cases
	if(lights[0] > d){
		d = lights[0];
	}
	if(l - lights[n-1] > d){
		d = l - lights[n-1];
	}

	printf("%.10f", d);
	
	return 0;
}

