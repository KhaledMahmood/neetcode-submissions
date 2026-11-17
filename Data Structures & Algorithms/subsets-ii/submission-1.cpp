class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(begin(nums), end(nums));

        process(0, {}, nums);

        return res;
        
    }

    void process(int i, vector<int> subs, vector<int>& nums) {
        res.push_back(subs);

        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;

            subs.push_back(nums[j]);
            process(j + 1, subs, nums);
            subs.pop_back();
        }
    }
};
