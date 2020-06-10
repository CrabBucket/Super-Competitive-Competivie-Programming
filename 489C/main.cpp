#include <iostream>
#include <vector>

using namespace std;

vector<int> constructSmallest(int m, int s){
    vector<int> digits(m, 0);
    while(m--){
        if(s > 9){
            digits[m] = 9;
            s -= 9;
        }
        else if(s < 10){
            digits[m] = s-1;
            if(m == 0){
                digits[m] += 1;
            }
            else{
                digits[0] = 1;
            }
            return digits;
        }
    }
}

vector<int> constructLargest(int m, int s){
    vector<int> digits;
    while(s >= 9){
        digits.push_back(9);
        s -= 9;
    }
    while(digits.size() != m){
        digits.push_back(s);
        s = 0;
    }
    return digits;
}

int main()
{
    int m, s;
    cin >> m >> s;

    //Edge cases
    if(m == 1 and s == 0){
        cout << "0 0" << endl;
        return 0;
    }
    if(!s){
        cout << "-1 -1" << endl;
        return 0;
    }
    if(s > m*9){
        cout << "-1 -1" << endl;
        return 0;
    }
    vector<int> small = constructSmallest(m, s);
    vector<int> large = constructLargest(m, s);
    for(int i : small){
        cout << i;
    }
    cout << ' ' << endl;
    for(int i : large){
        cout << i;
    }
    cout << endl;
    return 0;
}
