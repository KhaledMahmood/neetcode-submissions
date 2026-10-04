class Solution {
public:
    string longestPalindrome(string s) {

        int len = s.size();
        int resIdx, resLen = 0;
        vector<vector<bool>> paliIdx(len, vector<bool>(len, false));

        for(int i = s.size()-1; i >= 0; --i) {
            for(int j = i; j < s.size(); j++) {
                len = j-i+1;
                if(s[i] == s[j] && ((len <= 2) || paliIdx[i+1][j-1]))  {
                    paliIdx[i][j] = true;
                    if(resLen < len) {
                        resLen = len;
                        resIdx = i;
                    }
                }
            }
        }

        return s.substr(resIdx, resLen);
    }
};
