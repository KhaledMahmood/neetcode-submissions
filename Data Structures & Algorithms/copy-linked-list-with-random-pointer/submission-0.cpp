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

        unordered_map<Node*, Node*> addrMap ={};

        Node* nwList = nullptr;
        Node** nwHead = &nwList;

        while (head) {
            *nwHead = new Node(head->val);
            (*nwHead)->random = head->random;
            addrMap[head] = *nwHead;

            nwHead = &((*nwHead)->next);
            head = head->next;
        }

        auto hd = nwList;
        while(hd) {
            if(hd->random != nullptr)
                hd->random = addrMap[hd->random];

            hd = hd->next;
        }

        return nwList;
    }

};
