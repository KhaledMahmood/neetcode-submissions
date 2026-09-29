class PrefixTree {

private:
    struct TrieNode {
        unordered_map<char, TrieNode*> tree;
        bool isEnd = false;
    };

    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {

        TrieNode* cur = root;
        
        for(char& c: word) {
            if(cur->tree.find(c) == end(cur->tree)) {
                cur->tree[c] = new TrieNode();
            }
            cur = cur->tree[c];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for(char& c: word) {
            if(node->tree.find(c) == end(node->tree)) {
                return false;
            }
            node = node->tree[c];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {

        TrieNode* node = root;
        for(auto& c: prefix) {
            auto pos = node->tree.find(c);
            if(end(node->tree) == pos) {
                return false;
            }
            node = pos->second;
        }

        return true;
    }

};
