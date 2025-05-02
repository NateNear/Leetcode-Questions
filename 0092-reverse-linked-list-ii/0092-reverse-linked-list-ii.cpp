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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;

        ListNode* curr = temp;
        
        for(int i=0; i<left-1; i++){
            curr = curr->next;
        }
        ListNode* LP = curr;
        curr = curr->next;
        // curr->next = NULL;

        ListNode* prev = NULL;
        ListNode* fwd = curr->next;
        int cnt = right-left+1;

        for(int i=0; i<cnt; i++){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        LP->next->next = curr;
        LP->next = prev;

        return temp->next;
    }
};