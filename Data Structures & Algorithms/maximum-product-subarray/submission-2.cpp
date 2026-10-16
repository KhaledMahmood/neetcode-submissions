class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxP = nums[0];
        int locMax = 1, locMin = 1; // local max/min

        for(int i = 0; i < nums.size(); ++i) {
            int maxx = nums[i] * locMax;

            locMax = max(max(maxx, nums[i] * locMin), nums[i]);
            locMin = min(min(maxx, nums[i] * locMin), nums[i]);
            
            if(maxP < locMax) {
                maxP = locMax;
            }
        }

        return maxP;
        
    }
};
