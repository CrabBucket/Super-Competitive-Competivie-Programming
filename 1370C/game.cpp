#include <iostream>
#include <vector>
#include <array>
using namespace std;
vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

bool winner(long long num){
    if (num == 1){
        return false;
    }
    if (num%2 == 1){
        return true;
    }
    if (num == 2){
        return true;
    }
    vector<long long> factors = trial_division3(num);
    //cout << "Here" << endl;
    int evendivs = 0;
    while(factors.size() > 0 and factors[0] == 2){
        factors.erase(factors.begin());
        evendivs++;
    }
    if (evendivs > 0 and factors.size() == 0){
        return false;
    }
    if (factors.size() == 1){
        if(evendivs == 1){
            return false;
        }else{
            return true;
        }
    }
    if (evendivs == 1){
        return true;
    }
    else{
        return true;
    }

}
int main() {
    int cases;
    cin >> cases;
    bool win;
    long long num;
    while(cases--){
        cin >> num;
        win = winner(num);
        if (win){
            cout << "Ashishgup" << endl;
        }else{
            cout << "FastestFinger" << endl;
        }
    }
    
}