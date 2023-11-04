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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(-1);
        ListNode* oddH = odd;
        ListNode* even = new ListNode(-1);
        ListNode* evenH = even;
        ListNode* temp = head;

        int i = 1;

        while(temp){
            if(i%2 == 0){
                even->next = temp;
                temp = temp->next;
                even = even->next;
                even->next = NULL;
            }
            else{
                odd->next = temp;
                temp = temp->next;
                odd = odd->next;
                odd->next = NULL;
            }
            i++;
        }

        odd->next = evenH->next;

        return head;

    }
};