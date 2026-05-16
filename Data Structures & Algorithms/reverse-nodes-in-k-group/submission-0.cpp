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
    ListNode* getKth(ListNode* curr, int k ) {
        while ( curr && k > 0) {
            curr = curr->next; 
            k--; 
        }
        return curr; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0); 
        dummy->next = head; 
        ListNode* groupPrev = dummy; 

        while (true ) {
            ListNode* kth = getKth(groupPrev, k); 
            if (!kth) break; 
            
            ListNode* curr = groupPrev->next; 
            ListNode* groupNext = kth->next;  
            ListNode* prev = groupNext; 

            while ( curr != groupNext) {
                ListNode* nxt = curr->next; 
                curr->next = prev; 
                prev = curr; 
                curr = nxt; 
            }
            ListNode* temp = groupPrev->next; 
            groupPrev->next = kth; 
            groupPrev = temp; 
        }
        return dummy->next; 
    }
};
