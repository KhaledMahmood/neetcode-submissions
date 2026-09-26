class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> idx;
        perm(idx, nums);

        return res;
    }

    void perm(vector<int>& idx, vector<int>& nums) {

        if(idx.size() == nums.size()) {
            vector<int> vals;
            for(auto& i: idx) {
                vals.push_back(nums[i]);
            }
            res.emplace_back(vals);
            return;
        }

        for(int i = 0; i < nums.size(); ++i) {

            if(find(begin(idx), end(idx), i) != end(idx)) {
                continue;
            }

            idx.push_back(i);
            perm(idx, nums);
            idx.pop_back();
        }

    }
};
