class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> idx = {};
        for(int i = 0; i < nums.size(); i++) {
            idx[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++) {

            auto pos = idx.find(target-nums[i]);
            if(pos != idx.end() && (i != pos->second)) {
                return {i, pos->second};
            }
        }

        // Should never reach as one ans exists
        return {};
        
    }
};
