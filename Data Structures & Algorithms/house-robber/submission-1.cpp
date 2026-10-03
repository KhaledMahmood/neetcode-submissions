class Solution {
    vector<int> amt;
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        amt.resize(nums.size());

        for(int i = 0; i < n; ++i) {
            amt[i] = nums[i] + max((i - 2 >= 0 ? amt[i-2] : 0), 
                                    (i - 3 >= 0 ? amt[i-3] : 0));

        }

        return max(*(end(amt)-2), *(end(amt) - 1));
    }

    void dyn(int i, vector<int>& nums) {
        
    }
};
