#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string input;
    getline(cin, input);
    while(input != "0"){
        int result = 0;
        int multipland, count = 1;
        string::reverse_iterator it = input.rbegin();
        for(; it != input.rend(); it++){
            multipland = (int) pow(2,count++) - 1;
            result += (*it - '0') * multipland;
        }
        cout << result << endl;
        getline(cin, input);
    }
}

