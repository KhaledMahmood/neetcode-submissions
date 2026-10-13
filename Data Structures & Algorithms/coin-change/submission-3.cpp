class Solution {

    unordered_map<int, int> dp;
public:
    int coinChange(vector<int>& coins, int amount) {

        int res = process(amount, coins);

        return res == INT_MAX ? -1 : res;
    }

    int process(int amt, vector<int>& co) {
        
        if(amt == 0) {
            return 0;
        }

        if(auto pos = dp.find(amt); pos != end(dp)) {
            return pos->second;
        }

        int c = 0, minC = INT_MAX;
        for(int i = 0; i < co.size(); ++i) {
            if(amt - co[i] >= 0) {
                c = process(amt - co[i], co);
                if(c != INT_MAX) {
                    minC = min(c + 1, minC);
                }
            }
        }

        dp[amt] = minC;

        return dp[amt];
    }
};
