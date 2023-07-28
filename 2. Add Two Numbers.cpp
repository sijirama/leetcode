#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// string combination of the values in the LL

int getheValues(ListNode *l1) {
    ListNode *temp = l1;
    string ans = "";
    while (temp != nullptr) {
        ans += to_string(temp->val);
        temp = temp->next;
    }
    reverse(ans.begin(), ans.end());
    return stoll(ans);
}

void insert(ListNode *&head, int i) {
    ListNode *temp = new ListNode(i);
    if (head == nullptr) {
        head = temp;
        return;
    }
    ListNode *curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    int num1 = getheValues(l1);
    int num2 = getheValues(l2);
    cout << num1 + num2 << endl;
    string sum = to_string(num1 + num2);
    reverse(sum.begin(), sum.end());
    for (int i = 0; i < sum.size(); ++i) {
        insert(head, static_cast<int>(sum[i]) - 48);
    }
    return head;
}
