class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(begin(nums), end(nums));

        ans.insert(end(ans), begin(nums), end(nums));

        return ans;
        
    }
};