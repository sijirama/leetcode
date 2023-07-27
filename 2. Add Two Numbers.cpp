#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

std::string returnSum(ListNode *l1, std::string sum) {
    if (l1 == nullptr)
        return sum;
    sum += std::to_string(l1->val);
    return returnSum(l1->next, sum);
}

void insert(ListNode **Head, char data) {
    ListNode *temp = new ListNode();
    temp->next = nullptr;
    temp->val = int(data) - 48;
    if (*Head == nullptr) {
        *Head = temp;
        return;
    }

    ListNode *curr = *Head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = temp;
}

ListNode *getLinkedList(int nums) {
    std::string data = std::to_string(nums);
    ListNode *Head = nullptr;
    ListNode *Counter = Head;

    if (data.empty())
        return Head;
    int i = 0;
    std::reverse(data.begin(), data.end());
    while (i < data.size()) {
        insert(&Head, data[i]);
        ++i;
    }

    return Head;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *Answer = new ListNode();
    std::string sum1char = returnSum(l1, "");
    std::string sum2char = returnSum(l2, "");

    // if (sum1char.size() > 1) {
    //     std::reverse(sum1char.begin(), sum1char.end());
    // }
    //
    // if (sum2char.size() > 1) {
    //     std::reverse(sum2char.begin(), sum2char.end());
    // }
    // int sum1 = stoi(sum1char);
    // int sum2 = stoi(sum2char);
    int sum1 = 0;
    int sum2 = 0;

    // Parse the sum1char and sum2char strings in reverse order
    for (char c : sum1char) {
        sum1 = sum1 * 10 + (c - '0');
    }

    for (char c : sum2char) {
        sum2 = sum2 * 10 + (c - '0');
    }
    Answer = getLinkedList(sum1 + sum2);
    return Answer;
}
