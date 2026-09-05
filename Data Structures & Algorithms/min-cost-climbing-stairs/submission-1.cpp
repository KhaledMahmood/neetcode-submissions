class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        for(int it = 2; it < cost.size(); it++) {
            cost[it] += min(cost[it-1], cost[it-2]);
        }
        
        return min(cost[cost.size() - 1], cost[cost.size() - 2]);
    }
};
