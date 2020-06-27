#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//initial input
	double Trise;
	cin >> Trise;
	
	while(!cin.eof()){
		//edge case
		if(Trise <= 7.75){
			cout << "0 0.00 0.00" << endl;
			cin >> Trise;
			continue;
		}
		//main calculation
		int s = Trise / 7.75;
		double r = Trise / (double)(s+1);
		double Tmin = (24-2*r) * (double)s;
		double Tmax = Tmin + s;
		printf("%d %.2f %.2f\n", s, Tmin, Tmax);
		//get input and repeat
		cin >> Trise;
	}
	return 0;
}