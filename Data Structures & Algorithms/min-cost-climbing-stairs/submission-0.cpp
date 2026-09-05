class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        
        vector<int> minCost;
        minCost.resize(cost.size());
        minCost[0] = cost[0];
        minCost[1] = cost[1];

        for(int it = 2; it < cost.size(); it++) {
            minCost[it] = min(minCost[it-1], minCost[it-2]) + cost[it];
        }
        
        return min(minCost[minCost.size() - 1], minCost[minCost.size() - 2]);
    }
};
