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
    ListNode* recurse(ListNode* &head){
        
        if(head == NULL || head->next ==NULL){
            return head;
        }

        ListNode* curr = head->next;
        ListNode* fwd = curr->next;


        head->next = recurse(head->next->next);
        curr->next = head;
        return curr;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* ans = recurse(head);

        return ans;
    }
};