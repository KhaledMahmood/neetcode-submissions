class Solution {

    vector<vector<string>> res;

public:
    vector<vector<string>> partition(string s) {

        vector<string> stringList;

        process(0, s, stringList);

        return res;
    }

    void process(int i, string& s, vector<string>& sList) {
        if(i == s.size()) {
            res.push_back(sList);
            return;
        }

        for(int j = i; j < s.size(); ++j) {
            if(isPalin(i, j, s)) {
                sList.push_back(s.substr(i, j - i + 1));
                process(j+1, s, sList);
                sList.pop_back();
            }
        }

    }

    bool isPalin(int i, int j, string& s) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            ++i;
            --j;
        }

        return true;
    }
};
