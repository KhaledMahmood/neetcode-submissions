class WordDictionary {
    struct TrieNode {
        unordered_map<char, TrieNode*> paths;
        bool isEnd = false;
    };

    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* n = root;
        for(char& w: word) {
            if(end(n->paths) == n->paths.find(w)) {
                n->paths[w] = new TrieNode();
            }
            n = n->paths[w];
        }

        n->isEnd = true;
    }
    
    bool search(string word) {
        return recurSearch(word, root);
    }

    bool recurSearch(string word, TrieNode* n) {

        for(int i = 0; i < word.size(); ++i) {
            if(word[i] != '.') {
                if(end(n->paths) == n->paths.find(word[i])) {
                    return false;
                } else {
                    n = n->paths[word[i]];
                }
            } else {
                for(auto& [k, v]: n->paths) {
                    if(recurSearch(word.substr(i+1), v)) {
                        return true;
                    }
                }
                return false;
            } 
        }

        return n->isEnd;
    }
};
