#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;

int main() {
  vector<ull> fibonacci{0,1,2};

  for(int i = 3; i <= 50; i++)
    fibonacci.push_back(fibonacci[i-2] + fibonacci[i-1]);

  int input;
  cin >> input;
  while(input){
    cout << fibonacci[input] << endl;
    cin >> input;
  }
  return 0;
}