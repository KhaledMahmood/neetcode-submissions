class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {

        vector<string> strList;
        process(0,0,s, strList);

        return res;
    }

private:

    void process(int left, int right, string s, vector<string>& sl) {
        if(right == s.size()) {
            if(left == right) {
                res.push_back(sl);
            }
            return;
        }

        if(isPalindrome(s, left, right)) {
            sl.push_back(s.substr(left, right-left+1));
            process(right + 1, right + 1, s, sl);
            sl.pop_back();
        }

        process(left, right + 1, s, sl);
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if(s[l] != s[r]) return false;
            ++l;
            --r;
        }

        return true;
    }
};
