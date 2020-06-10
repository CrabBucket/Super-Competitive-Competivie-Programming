#include <iostream>
#include <vector>

using namespace std;

int main(){
    //get input
    int n;
    cin >> n;
    vector<int> nums;
    //nums.reserve(n);
    int temp;
    while(n--){
        cin >> temp;
        nums.push_back(temp);
    }

    //solve problem
    int odds = 0, evens = 0;
    int firstOdd = -1, firstEven = -1;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2){
            odds += 1;
            if(firstOdd == -1)
                firstOdd = i;
        }
        else{
            evens += 1;
            if(firstEven == -1)
                firstEven = i;
        }
    }
    //account for index starting at 1
    firstOdd  += 1;
    firstEven += 1;
    //print result
    cout << ( odds < evens ? firstOdd : firstEven ) << endl;
    return 0;
}
