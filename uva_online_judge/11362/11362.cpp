#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool collisions(vector<string>& numbers){
  for(int i = 1; i < numbers.size(); i++){
    if(numbers[i].find(numbers[i-1]) == 0){
      return true;
    }
  }
  return false;
}

int main() {
  int t, n;
  string number;
  cin >> t;

  while(t--){
    cin >> n;
    cin.ignore();
    vector<string> numbers;
    numbers.reserve(n);
    for(int i = 0; i < n; i++){
      getline(cin, number);
      numbers.emplace_back(number);
    }
    sort(numbers.begin(), numbers.end());
    cout << (collisions(numbers) ? "NO" : "YES") << endl;
  } 
}