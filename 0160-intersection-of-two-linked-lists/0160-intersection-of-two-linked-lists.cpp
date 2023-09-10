/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) 
            return NULL;

        ListNode * temp1 = headA;
        ListNode * temp2 = headB;
        
        int countA=0;
        int countB=0;

        while(temp1!=NULL){
            countA++;
            temp1=temp1->next;
        }

        while(temp2!=NULL){
            countB++;
            temp2=temp2->next;
        }
        
        temp1 = headA;
        temp2 = headB;

        if(countA>countB){
            while(countA>countB){
                temp1 = temp1->next;
                countA--;
            }
        }

        if(countB>countA){
            while(countB>countA){
                temp2 = temp2->next;
                countB--;
            }
        }

        while(temp1 && temp2){
            if(temp1==temp2){
                return temp1;
            }
            temp1= temp1->next;
            temp2 = temp2->next;
        }
        
        return 0;         
    }
};