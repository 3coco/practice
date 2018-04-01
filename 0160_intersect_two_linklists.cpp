// https://leetcode.com/problems/intersection-of-two-linked-lists/description/

#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Soultion160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        ListNode *curA, *curB;
        
        if(lenA < lenB) {
           swap(lenA, lenB);
           swap(headA, headB);
        }

        curA = headA;
        curB = headB;
        for(int i = 0; i < lenA - lenB; i++) {
            curA = curA -> next;
        }

        while(curA != NULL && curB != NULL) {
            if(curA == curB) {
                return curA;
            }
            curA = curA -> next;
            curB = curB -> next;
        }

        return NULL;
    }
private:
    int getListLength(ListNode *head) {
        int count = 0;
        ListNode *cur = head;
        while(cur != NULL) {
            count++;
            cur = cur->next;
        }
        return count;
    }
};

