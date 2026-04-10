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
        
        unordered_map<Node*, Node*> map;
        map[nullptr] = nullptr;

        Node* curr = head;
        while(curr){

            if(map.find(curr) == map.end()){
                map[curr] = new Node(0);
            }map[curr]->val = curr->val;

            if(map.find(curr->next) == map.end()){
                map[curr->next] = new Node(0);
            }map[curr]->next = map[curr->next];

            if(map.find(curr->random) == map.end()){
                map[curr->random] = new Node(0);
            }map[curr]->random = map[curr->random];

            curr = curr->next;

        }

        return map[head];
    }
};
