#include <iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a;
	cin >> n >> m >> a;
	long long rows, cols;
	rows = (n % a == 0) ? n/a : n/a + 1;
	cols = (m % a == 0) ? m/a : m/a + 1;
	cout << rows * cols;
	return 0;
}