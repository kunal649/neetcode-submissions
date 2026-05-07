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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0); 
        dummy->next = head; 
        
        ListNode* lbreakpoint = dummy; 
        ListNode* curr = head; 
        for (int i = 1; i < left ; i++) {
            lbreakpoint = lbreakpoint->next; 
            curr = curr->next; 
        }

        ListNode* rbreakpoint = curr; 
        ListNode* prev = nullptr; 
        for ( int i = 0; i <= right - left; i++) {
            ListNode* nxt = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = nxt; 
        }
        lbreakpoint->next = prev; 
        rbreakpoint->next = curr; 

        return dummy->next; 
    }
};