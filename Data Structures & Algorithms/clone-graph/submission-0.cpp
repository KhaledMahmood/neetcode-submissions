/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

    unordered_map<int, Node*> dict;
    
public:
    Node* cloneGraph(Node* node) {
        return process(node);
    }

    Node* process(Node* node) {
        if(node == nullptr) {
            return nullptr;
        }

        if(dict.find(node->val) == end(dict)) {
            dict[node->val] = new Node(node->val);
        }

        for(auto n: node->neighbors) {
            if(dict.find(n->val) != end(dict)) {
                dict[node->val]->neighbors.push_back(dict[n->val]);
            } else {
                dict[node->val]->neighbors.push_back(process(n));
            }
        }

        return dict[node->val];
    }
};
