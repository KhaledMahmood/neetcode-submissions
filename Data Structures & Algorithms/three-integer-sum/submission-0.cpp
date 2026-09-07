class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        unordered_map<int, int> lastIdx;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            lastIdx[nums[i]] = i;
        }

        for(int i = 0; i < nums.size()-2; i++) {

            if(i > 0 && nums[i] == nums[i-1]) continue;

            for(int j = i+1; j < nums.size()-1; j++) {

                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int diff = 0 - (nums[i]+nums[j]);

                auto idx = lastIdx.find(diff);
                if(idx != lastIdx.end() && ((idx->second > j))) {
                    // cout << i << ", " << j << ", " << idx->second << ", diff: " << diff << endl;
                    res.push_back({nums[i], nums[j], idx->first});
                }
            }
        }

        return res;
    }
};
