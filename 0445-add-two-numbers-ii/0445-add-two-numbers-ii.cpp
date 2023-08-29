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
    ListNode* rev(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* fwd = NULL;

        while(curr!=NULL){
            fwd = curr->next;
            curr-> next =prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    ListNode* add(ListNode* head1, ListNode* head2){
        ListNode* first = head1;
        ListNode* second = head2;
        
        ListNode*head = NULL;
        ListNode*tail = NULL;

        int carry = 0;
        int sum,digit = 0;
        while(first!=NULL && second!=NULL){
            sum = carry + first->val + second->val;
            digit  = sum%10;
            carry = sum/10;
            insertAtTail(head, tail, digit);

            first = first->next;
            second = second->next;
        }

        while(first!=NULL){
            sum = carry + first->val;
            digit  = sum%10;
            carry = sum/10;
            insertAtTail(head, tail, digit);

            first = first->next;
        }
        
        while(second !=NULL){
            sum = carry + second->val;
            digit  = sum%10;
            carry = sum/10;
            insertAtTail(head, tail, digit);

            second = second->next;
        }
        
        while(carry!=0){
            sum = carry;
            digit  = sum%10;
            carry = sum/10;
            insertAtTail(head, tail, digit);
        }
        return head;
    }

    ListNode* insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* node = new ListNode(val);

        if(head == NULL){
            head = node;
            tail = node;
            return head;
        }
        else{
            tail->next = node;
            tail = node;
        }
        return head;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = rev(l1);
        ListNode* second = rev(l2);

        ListNode* ans = add(first, second);

        return rev(ans);
    }
};