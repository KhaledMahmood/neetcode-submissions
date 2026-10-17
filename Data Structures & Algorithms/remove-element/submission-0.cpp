class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int cnt = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == val) {
                nums[i] = INT_MAX;
                ++cnt;
            }
        }

        sort(begin(nums), end(nums));

        return nums.size() - cnt;
    }
};