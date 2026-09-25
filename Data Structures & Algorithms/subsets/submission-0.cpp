class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        return process(0, nums);
        
    }

private:
    vector<vector<int>> process(int i, vector<int>& nums) {

        if(i == nums.size()) {
            return {{}};
        }

        vector<vector<int>> val = process(i+1, nums);
        vector<vector<int>> res(val);

        for(auto& v: val) {
            v.insert(v.begin(), nums[i]);
        }
        res.insert(res.end(), val.begin(), val.end());

        return res;
    }
};
