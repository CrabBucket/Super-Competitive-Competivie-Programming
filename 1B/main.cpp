#include <iostream>
#include <string>

using namespace std;

bool isSystem2(string s){
    //catchs instance of num then letter '9C'
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] >= '0' and s[i] <= '9'){
            if(s[i+1] > '9'){
                return true;
            }
        }
    }
    return false;
}

//converts to letters ex:703 to AAA, basically
//base conversion with some special case checking
string toLetters(int n){
    string result = "";
    while(n != 0){
        //handle Z cases
        int temp = n % 26;
        if(temp == 0){
            result = "Z" + result;
            n -= 26;
        }

        else{
            string tempStr(1, temp + 'A' - 1);
            result = tempStr + result;
        }
        n /= 26;
    }
    return result;
}

//System 1 ex: BC23
string toSystem1(string s){
    int rowNum = -1, colNum = -1;
    size_t cLocation = s.find('C');
    rowNum = stoi(s.substr(1,cLocation-1));
    colNum = stoi(s.substr(cLocation+1, s.size() - cLocation - 1));
    return toLetters(colNum) + to_string(rowNum);
}

//AAA -> 703
int toNums(string s){
    int result = 0;
    int powers[] = {1,26,676,17576,456976};
    int i = s.size()-1;
    for(char c : s){
        int coey = c - 'A' + 1;
        result += coey * powers[i--];
    }
    return result;
}

//System 2 ex: R23C55
string toSystem2(string s){
    //get where nums start
    int numsAt = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= '9'){
            numsAt = i;
            break;
        }
    }
    string letters = s.substr(0,numsAt);
    int rowNum = stoi(s.substr(numsAt, s.size() - numsAt));
    int colNum = toNums(letters);
    return "R" + to_string(rowNum) + "C" + to_string(colNum);
}

int main()
{
    int cases;
    cin >> cases;
    cin.ignore();
    string s;
    while(cases--){
        getline(cin, s);
        if(isSystem2(s)){
            cout << toSystem1(s) << endl;
        }
        else{
            cout << toSystem2(s) << endl;
        }
    }
    return 0;
}
