// https://leetcode.com/problems/remove-linked-list-elements/description/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {};
};

class Solution203 {
public:
    // Solution 1: iterative
    ListNode* removeElements(ListNode *head, int val) {
        ListNode **list = &head;

        while(*list != nullptr) {
            if((*list) -> val == val) {
                *list = (*list) -> next;
            } else {
                list = &((*list) -> next);
            }
        }

        return head;
    }

    // Solution 2: recursion
    ListNode *removeElements2(ListNode *head, int val) {
        removeElementsHelp(&head, val);
        return head;
    }
private:
    void removeElementsHelp(ListNode **head, int val) {
        if (*head == nullptr){
            return;
        } else if((*head)->val == val) {
            *head = (*head)->next;
            removeElementsHelp(head, val);
        } else {
            removeElementsHelp(&((*head)->next), val);
        }    
    }
};

bool isLinkedListEqual(ListNode *h1, ListNode *h2) {
    if(h1 == nullptr && h2 == nullptr) {
        return true;
    }

    ListNode *l1 = h1, *l2 = h2;
    while(l1 != nullptr && l2!= nullptr) {
        if(l1 -> val != l2 -> val) {
            return false;
        }
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    if(l1 == nullptr && l2 == nullptr) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Solution203 sol;
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);

    ListNode *node12 = new ListNode(1);
    ListNode *node22 = new ListNode(2);
    ListNode *node32 = new ListNode(3);

    ListNode *head1 = node1;
    head1 -> next = node2;
    head1 -> next -> next = node3;

    ListNode *ans1 = node22;
    ans1 -> next = node32;

    if(!isLinkedListEqual(sol.removeElements(head1, 1), ans1)) {
        cout << "Test #1 failed" << endl;
    }

     ListNode *head2 = node1;
     head2 -> next = node2;
     head2 -> next -> next = node3;

     ListNode *ans2 = node12;
     ans2 -> next = node32;

    if(!isLinkedListEqual(sol.removeElements(head2, 2), ans2)) {
         cout << "Test #2 failed" << endl;
    }

    ListNode *head3 = node1;
    head3 -> next = node2;
    head3 -> next -> next = node3;

    ListNode *ans3 = node12;
    ans3 -> next = node22;
    ans3 -> next -> next = NULL;
    
    if(!isLinkedListEqual(sol.removeElements(head3, 3), ans3)) {
          cout << "Test #3 failed" << endl;
    }

    return 0;
}
