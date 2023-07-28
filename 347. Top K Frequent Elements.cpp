#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> map;
    std::map<int, int>::iterator it = map.begin();
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] += 1;
    }

    vector<int> ans;
    int count = 0;
    while (it != map.end() && count < k) {
        if (it->second > 1) {
            ans.emplace_back(it->first);
        }
        ++count;
        ++it;
    }
    return ans;
}
