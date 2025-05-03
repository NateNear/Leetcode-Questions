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
    bool hasCycle(ListNode* head) {
        ListNode* temp = head;
        unordered_map<ListNode*, bool> visited;

        while(temp != NULL){
            if(visited[temp] != true){
                visited[temp] = true;
                temp = temp->next;
            }
            else return true;
        }
        return false;
    }
};