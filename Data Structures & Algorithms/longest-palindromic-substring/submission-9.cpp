class Solution {
    
public:
    string longestPalindrome(string s) {

        int len = 0;
        int palIdx = -1, palLen = 0;
        vector<vector<bool>> paliIdx = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));

        for(int i = s.size()-1; i >= 0; --i) {
            for(int j = i; j < s.size(); ++j) {
                len = j-i+1;
                if(s[i] == s[j] && (len <= 3 || paliIdx[i+1][j-1])) {
                    paliIdx[i][j] = true;
                    if(palLen < len) {
                        palIdx = i;
                        palLen = len;
                    }
                }
            }
        }

        return s.substr(palIdx, palLen);
    }
};
