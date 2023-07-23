/*
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all the elements of nums except nums[i]. The product of any
prefix or suffix of nums is guaranteed to fit in a 32-bit integer. You must
write an algorithm that runs in O(n) time and without using the division
operation.
*/
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> Result;
    for (int i = 0; i < nums.size(); ++i) {
        int data = 1;
        for (int j = 0; j < nums.size(); ++j) {
            if (i == j)
                continue;
            data *= nums[j];
        }
        Result.push_back(data);
    }
    return Result;
}

int main() {
    vector<int> que = {1, 2, 3, 4};
    auto ans = productExceptSelf(que);
    cout << "[";
    for (auto i : ans) {
        cout << i << ",";
    }
    cout << "]";
}
