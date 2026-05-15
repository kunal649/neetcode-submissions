/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp; 
        Node* curr = head; 

        // Create new nodes and store them such that they corresponds  to original nodes. 
        while ( curr != nullptr ) {
            mp[curr] = new Node(curr->val); 
            curr = curr->next; 
        }
         
        // 
        curr = head; 
        while ( curr != nullptr ) {
            if (curr->next) 
             mp[curr]->next = mp[curr->next]; 
            if (curr->random) 
            mp[curr]->random = mp[curr->random]; 

            curr = curr->next; 
        }
        return mp[head]; 
    }
};
