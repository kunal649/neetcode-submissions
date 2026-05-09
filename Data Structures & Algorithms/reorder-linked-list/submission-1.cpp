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
        //discovering the mid. 
        ListNode* slow = head;
        ListNode* fast = head; 

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next; 
            fast = fast->next->next; 
        }
        ListNode* second = slow->next ; 
        slow->next = nullptr; 

        // reversing the other half (after mid)
        ListNode* prev = nullptr; 
        ListNode* curr = second; 

        while (curr != nullptr) {
            ListNode* nxt = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = nxt; 
        }
         
         ListNode* left = head;
         ListNode* right = prev; 
         while (right != nullptr) {
            ListNode* l = left->next; 
            ListNode* r = right->next; 
            left->next = right; 
            right->next = l; 
            left = l; 
            right = r; 
         }
    }
};
