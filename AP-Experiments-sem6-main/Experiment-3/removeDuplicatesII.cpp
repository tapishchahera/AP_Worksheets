/*
Given the head of a sorted linked list, delete all nodes that have
 duplicate numbers, leaving only distinct numbers from the original list. 
 Return the linked list sorted as well.
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O( n ), where n is the number of nodes in the list. We traverse each node once.
// Space Complexity: O(1)

struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

ListNode* deleteDuplicates(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    while (head) {
        while (head->next && head->val == head->next->val)
        head = head->next;
        if (prev->next == head)
        prev = prev->next;
        else
        prev->next = head->next;
        head = head->next;
    }

    return dummy.next;
    }

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);

    ListNode* res = deleteDuplicates(head);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}