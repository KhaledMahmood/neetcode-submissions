class Solution {
public:
    int search(vector<int>& nums, int target) {

        return getPos(0, nums.size()-1, target, nums);
        
    }

    int getPos(int start, int end, int val, const vector<int>& nums) {

        if(start > end) return -1;

        int mid = (start+end)/2;

        if(nums[mid] == val) return mid;
        else if(nums[mid] < val) return getPos(mid+1, end, val, nums);
        else return getPos(start, mid-1, val, nums);
    }
};
