/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            if (n < 1 || head == NULL) {
        return head;
    }

    int count = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    if (n > count) {
        return head;
    }
    
    int m = count - n;
    
    if (m == 0) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    temp = head;
    count = 0;
    while (count != m - 1 && temp != NULL) {
        count++;
        temp = temp->next;
    }

    if (temp != NULL && temp->next != NULL) {
        ListNode* nextt = temp->next->next;
        delete temp->next; 
        temp->next = nextt;
    }

    return head;
    }
};