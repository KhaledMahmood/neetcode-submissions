class Solution {
public:
    int countSubstrings(string s) {

        int count = 0, n = s.size();
        vector<vector<bool>> palis(n, vector<bool>(n, false));

        for(int i = n-1; i >= 0; --i) {
            for(int j = i; j < n; ++j) {
                if(s[i] == s[j] && (j-i+1 < 3 || palis[i+1][j-1])) {
                    ++count;
                    palis[i][j] = true;
                }
            }
        }

        return count;
    }
};
