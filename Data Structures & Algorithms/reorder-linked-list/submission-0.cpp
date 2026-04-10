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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* P = slow->next;
        ListNode* prev = slow->next = nullptr;

        while(P){
            ListNode* temp = P->next;
            P->next = prev;
            prev = P;
            P = temp;
        }

        ListNode* first = head;
        P = prev;

        while(P){
            ListNode* temp1 = first->next;
            ListNode* temp2 = P->next;

            first->next = P;
            P->next = temp1;

            first = temp1;
            P = temp2;
        }

        
    }
};
