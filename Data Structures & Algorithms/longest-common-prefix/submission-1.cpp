/*class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
    }
};*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {

        int prefLen = s[0].size();
        int j = 0, n = 0;

        for(int i = 1; i < s.size() && prefLen > 0; ++i) {
            j = 0;
            n = s[i].size();

            while(j < n && j < prefLen && s[0][j] == s[i][j]) {
                ++j;
            }

            if (j < prefLen) prefLen = j;

        }

        return s[0].substr(0, prefLen);
    }
};
