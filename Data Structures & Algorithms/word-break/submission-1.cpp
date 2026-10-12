class Solution {

    unordered_set<string> dict;
    vector<int> dp;

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for(auto& w: wordDict) {
            dict.insert(w);
        }

        dp = vector<int>(s.size(), -1);

        return process(0, s);
    }

    bool process(int i, string& s) {
        if(i == s.size()) {
            return true;
        }

        if(dp[i] != -1) {
            return dp[i] == 1;
        }

        string ss = s.substr(i);

        for(int j = s.size()-1; j >=i ; --j) {
            if(dict.contains(ss) && process(j+1, s)) {
                dp[i] = 1;
                return true;                
            }
            ss.pop_back();
        }

        dp[i] = 0;
        return false;
    }
};
