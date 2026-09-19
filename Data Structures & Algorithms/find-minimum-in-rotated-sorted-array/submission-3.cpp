class Solution {
public:
    int findMin(vector<int> &nums) {

        if(nums[0] < nums[nums.size() - 1]) {
            return nums[0];
        }

        return minVal(0, nums.size() - 1, nums);
        
    }

    int minVal(int start, int end, vector<int>& nums) {

        int n= 5;
        int res = nums[start];

        while(start <= end) {

            if(nums[start] <= nums[end]) {
                return min(res, nums[start]);
            }

            int mid = (start + end) / 2;

            res = min(res, nums[mid]);

            // cout << format("start: {}, end: {}, mid: {}, res: {}\n", start, end, mid, res);

            if(nums[start] <= nums[mid]) { // this part is sorted
                start = mid + 1;
            } else {
                end = mid - 1;
            }

        }

        return res;
    }

    
};
