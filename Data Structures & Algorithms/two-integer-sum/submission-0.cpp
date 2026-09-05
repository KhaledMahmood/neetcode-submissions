class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, vector<int>> idx;
        for(int i = 0; i < nums.size(); i++) {
            idx[nums[i]].push_back(i);
        }

        for(int i = 0; i < nums.size(); i++) {
            auto vIdx = idx[target-nums[i]];
            
            for(int j = 0; j < vIdx.size(); j++) {
                if(i != vIdx[j]) return {i, vIdx[j]};
            } 

        }

        // Should never reach as one ans exists
        return {};
        
    }
};
