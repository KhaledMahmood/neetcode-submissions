class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> pref(nums.size(),1);
        vector<int> suff(nums.size(),1);

        for(int i = 1; i < nums.size(); i++) {
            pref[i] = pref[i-1] * nums[i-1];
        }

        suff[suff.size()-1] = 1;
        for (int j = nums.size()-2; j >= 0; j--) {
            suff[j] = suff[j+1] * nums[j+1];
        }

        vector<int> res(nums.size());
        for(int i = 0; i < res.size(); i++) {
            res[i] = pref[i] * suff[i];
        }

        return res;

    }
};
