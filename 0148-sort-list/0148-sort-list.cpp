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
    ListNode* sortList(ListNode* head) {
        ListNode* temp = head;
        int count  = 0;

        while(temp!= NULL){
            count++;
            temp = temp->next;
        }
        temp = head;

        if(count>0){
            int arr[count];
            int i = 0;
            while(temp!= NULL){
                arr[i]=temp->val;
                temp = temp->next;
                i++;
            }
            sort(arr, arr+count);
            temp = head;
            i = 0;
            while(temp!=NULL){
                temp->val = arr[i];
                temp=temp->next;
                i++;
            }
        }
        return head;
    }
};