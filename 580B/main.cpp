#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pal{
    long long money;
    long long friendship;
};

//custom comparison function for sorting pals
bool cmp(pal a, pal b){
    return a.money < b.money;
}

int main(){
    //input data stored in here
    vector<pal> arr;

    //Input
    int n, d;
    cin >> n >> d;

    //parse input data
    int i = n;
    while(i--){
        int m, s;
        cin >> m >> s;
        pal p;
        p.money = m;
        p.friendship = s;
        arr.push_back(p);
    }

    //sort
    sort(arr.begin(), arr.end(), cmp);

    //Find all subsets and sum the ones which are not subsets of subsets
    long long maxSum = 0;
    vector<pal>::iterator oldRichGuy = arr.begin()-1;
    for(vector<pal>::iterator it = arr.begin(); it != arr.end(); it++){
        pal p;
        p.money = it->money + d;
        vector<pal>::iterator richGuy = lower_bound(it, arr.end(), p, cmp);
        //if subset is not subset of a previous one then skip it
        if(richGuy != oldRichGuy){
            long long sum = 0;
            for(vector<pal>::iterator cit = it; cit < richGuy; cit++){
                sum += cit->friendship;
            }
            if(sum > maxSum){
                maxSum = sum;
            }
        }
        oldRichGuy = richGuy;
    }

    cout << maxSum << endl;

    return 0;
}
