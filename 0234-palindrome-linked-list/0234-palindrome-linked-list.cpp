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
    ListNode* midele(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;

        while(curr!=NULL){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr= fwd;
        }

        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = midele(head);

        ListNode* temp = mid->next;
        
        ListNode*hide = mid->next = reverse(temp);

        ListNode* head1 = head;
        ListNode* head2  = hide;

        while(head2!=NULL){
            if(head1->val != head2->val){
                return 0;
            }

            head1=head1->next;
            head2 = head2->next;

        }
        mid->next = reverse(temp);
        return 1;
    }
};