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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int m = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            m++;
        }

        if(m == 1){
            delete head;
            return nullptr;
        }

        if(m == n){
            ListNode* temp = head;
            head = temp->next;
            delete temp;
            return head;
        }

        m = m-n;
        curr = head;
        for(int i = 1; i<m; i++){
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
        
    }
};
