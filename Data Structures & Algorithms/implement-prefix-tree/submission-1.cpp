class PrefixTree {

private:
    struct TrieNode {
        TrieNode* kids[26];
        bool isEnd = false;

        TrieNode() {
            for(int i = 0; i < 27; ++i) {
                kids[i] = nullptr;
            }
        }
    };

    TrieNode* root = new TrieNode();

public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        TrieNode* node = root;

        for(auto& c: word) {
            if(*(node->kids + (c - 'a')) == nullptr) {
                *(node->kids + (c - 'a')) = new TrieNode();
            }

            node = *(node->kids + (c - 'a'));
        }

        node->isEnd = true;
    }
    
    bool search(string word) {

        TrieNode* node = root;

        for(auto& c: word) {
            if(node->kids[c - 'a'] == nullptr) {
                return false;
            }
            node = node->kids[c - 'a'];
        }

        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;

        for(auto& c: prefix) {
            if(node->kids[c - 'a'] == nullptr) {
                return false;
            }
            node = node->kids[c - 'a'];
        }

        return true;
    }
};
