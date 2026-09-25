class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> idx;

        process(target, 0, nums, idx);

        return res;
    }

    void process(int target, int idx, vector<int>& nums, vector<int>& vals) {

        if(target < 0) {
            return;
        }

        if(target == 0) {
            res.push_back(vals);
            return;
        }

        for(int i = idx;  i < nums.size(); ++i) {
            vals.push_back(nums[i]);
            process(target-nums[i], i, nums, vals);
            vals.pop_back();
        }
    }
};
