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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* fwd;

        while(curr){
            fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }

    void func(ListNode*h1, ListNode*h2){
        if(h1==NULL || h2 == NULL ){
            return;
        }
        ListNode* nextH1 = h1->next;
        ListNode* nextH2 = h2->next;
        h1->next = h2;
        h2->next = nextH1;
        func(nextH1, nextH2);
        
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secH = slow->next;

        slow->next= NULL;

        ListNode*h2 = reverse(secH);

        ListNode*h1 = head;

        func(h1,h2);
    }
};