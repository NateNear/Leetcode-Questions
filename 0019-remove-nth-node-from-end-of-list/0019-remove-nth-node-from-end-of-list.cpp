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

    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd = curr;

        while(curr){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        head = prev;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* revHead = reverse(head);

        if (n == 1) {
            revHead = revHead->next;
            return reverse(revHead);
        }

        ListNode* temp = revHead;
        int cnt = 1;
        while(cnt < n-1){
            temp = temp->next;
            cnt++;
        }

        temp->next = temp->next->next;

        ListNode* ans = reverse(revHead);

        return ans;
    }
};