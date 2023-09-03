#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
  public:
    TreeNode *InsertFromArray(TreeNode *root, int num) {
        TreeNode *node = new TreeNode;
        node->val = num;
        node->right = nullptr;
        node->left = nullptr;

        if (root == nullptr) {
            root = node;
            return root;
        }

        TreeNode *temp = root;
        if (num > temp->val) {
            temp->right = InsertFromArray(temp->right, num);
        } else {
            temp->left = InsertFromArray(temp->left, num);
        }
        return temp;
    }

    int minVector(vector<int> &nums) {
        int val;
        if (nums.size() % 2 == 0) {
            val = nums[(nums.size() - 1) / 2];
            nums.erase(nums.begin() + ((nums.size() - 1) / 2));
        } else {
            val = nums[nums.size() / 2];
            nums.erase(nums.begin() + (nums.size() / 2));
        }
        return val;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums) {
        TreeNode *Head = nullptr;
        // root node
        Head = InsertFromArray(Head, this->minVector(nums));
        // rest of vector;
        for (int i = 0; i < nums.size(); i++) {
            // Head = this->InsertFromArray(Head, nums[i]);
            // Head = this->InsertFromArray(Head, this->minVector(nums));
        }
        return Head;
    }

    void inOrderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
};

int main() {
    TreeNode *root;
    Solution sol;
    vector<int> num = {0, 1, 2, 3, 4, 5};
    root = sol.sortedArrayToBST(num);
    cout << "----------------------------------------------\n";
    sol.inOrderTraversal(root);
    cout << endl;
    cout << root;
}
