#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;


vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    vector <bool> Result;
    auto m = max_element(candies.begin() , candies.end());
    int MAX = *m;

    for(int i = 0 ; i < candies.size() ; ++ i){
        if(candies[i] + extraCandies >= MAX){
            Result.push_back(true);
        }else{
            Result.push_back(false);
        }
    }
    return Result;
}

int main(){
    vector<int> que = {2,3,5,1,3};
    int candy = 3;

    auto result = kidsWithCandies(que,candy);
    for(auto boo : result){
        if(boo){
            cout << " True ";
            continue;
        }
        cout << " False ";
    }
}
