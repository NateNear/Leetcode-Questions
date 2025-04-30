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

    int getlen(ListNode* head){
        int len = 0;
        while(head!=NULL){
            len++;
            head=head->next;
        }
        return len;
    }

    ListNode* middleNode(ListNode* head) {
        int cnt = 1;
        int n = getlen(head);
        int mid  = (n/2) + 1;

        ListNode*curr = head;

        while(cnt<mid){
            curr = curr->next;
            cnt++;
        }

        return curr;
    }
};