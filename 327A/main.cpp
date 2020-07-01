/*
 3     2  2  3        1 1  2       7
000111001001000111111101010011110000000
    3   1  1      7    1 1    4

  3  0 2  3   5     -2 0 0 2  -2      7
        1  2          1 1             
*/

#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, nC;
	cin >> n;
	nC = n;

	//Use MSS algo to find longest stretch of 0's to flip
	int sum = 0, mss = 0, ones = 0, digits[n];
	while(n--) {
		cin >> digits[n];
		if(digits[n]) {
			sum--;
			ones++;
		}
		else 	      sum++;
        if(sum < 1)   sum = 0;
        if(sum > mss) mss = sum;
	}

	//handle edge case
	if(ones == nC)
		cout << nC - 1;
	else
		//add # of 1s plus # of zeros flipped
		cout << ones + mss;

	return 0;
}