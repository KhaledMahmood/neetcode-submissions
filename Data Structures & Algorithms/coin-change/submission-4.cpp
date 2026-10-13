class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int amt;
        vector<int> dp(amount+1, INT_MAX-1);

        dp[0] = 0;
        for(int a = 1; a <= amount; ++a) {
            for(const auto& c: coins) {
                amt = a - c;
                if(amt >= 0) {
                    dp[a] = min(dp[a], dp[amt] + 1);
                }
            }
        }

        return (dp[amount] == INT_MAX-1) ? -1 : dp[amount];
    }
};
