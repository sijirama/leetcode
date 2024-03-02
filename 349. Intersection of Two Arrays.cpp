#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <vector>

using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    set<int> S;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            if (nums1[i] == nums2[j]) {
                S.insert(nums1[i]);
            }
        }
    }

    vector<int> A = {S.begin(), S.end()};
    return A;
}
