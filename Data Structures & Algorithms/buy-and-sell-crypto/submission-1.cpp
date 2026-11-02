class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int min = prices[0];
        int pro = 0, max = 0;


        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < min) min = prices[i];

            pro = prices[i] - min;
            if(pro > max) max = pro;
        }

        return max;
        
    }
};
