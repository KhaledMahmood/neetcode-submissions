class Solution {

    vector<int> dp;
    
public:
    int numDecodings(string s) {

        dp = vector<int>(s.size(), -1);

        return process(0, s);
    }

    int process(int i, string& s) {
        if(i == s.size()) {
            return 1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int c = 0;

        for(int j = i; j-i < 2 && j < s.size(); ++j) {
            if((i == j && s[i] >= '1' && s[i] <= '9') ||
               ((s[i] == '1' && s[j] >= '0' && s[j] <= '9') ||
                (s[i] == '2' && s[j] >= '0' && s[j] <= '6'))) {
                c += process(j+1, s);
            }
        }

        dp[i] = c;

        return c;
    }
};
