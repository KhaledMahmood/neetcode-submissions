class Solution {
    vector<int> dp;
public:
    int lengthOfLIS(vector<int>& nums) {

        dp = vector<int>(nums.size(), -1);

        int maxL = 0;
        for(int i = 0; i < nums.size(); ++i) {
            maxL = max(maxL, process(i, nums));
        }
        
        return maxL;
        
    }

    int process(int i, vector<int>& n) {
        if(i == n.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        dp[i] = 1;
        for(int j = i + 1; j < n.size(); ++j) {
            if(n[i] < n[j]) {
                dp[i] = max(dp[i], 1 + process(j, n));
            }
        }

        return dp[i];
    }

};
