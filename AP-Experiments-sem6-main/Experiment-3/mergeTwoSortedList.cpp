/*
You are given the heads of two sorted linked lists list1 and list2. 
Merge the two lists into one sorted list. The list should be made by splicing 
together the nodes of the first two lists. Return the head of the merged linked list.
*/
//
#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + m), where n and m are the lengths of list1 and list2. We are traversing each list once.
// Space Complexity: O(1), we are not using any extra space.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;
    ListNode * ptr = list1;
    if(list1 -> val > list2 -> val) {
        ptr = list2;
        list2 = list2 -> next;
    }
    else list1 = list1 -> next;
    ListNode *curr = ptr;
    while(list1 &&  list2) {
        if(list1 -> val < list2 -> val){
            curr->next = list1;
            list1 = list1 -> next;
        }
        else {
            curr->next = list2;
            list2 = list2 -> next;
        }
        curr = curr -> next;  
    }
    if(!list1)
        curr -> next = list2;
    else
        curr -> next = list1;    
    return ptr;
}

int main() {
    ListNode *list1 = new ListNode(1);
    list1 -> next = new ListNode(2);
    list1 -> next -> next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2 -> next = new ListNode(3);
    list2 -> next -> next = new ListNode(4);
    ListNode *mergedList = mergeTwoLists(list1, list2);
    while(mergedList) {
        cout << mergedList -> val << " ";
        mergedList = mergedList -> next;
    }
    return 0;
}