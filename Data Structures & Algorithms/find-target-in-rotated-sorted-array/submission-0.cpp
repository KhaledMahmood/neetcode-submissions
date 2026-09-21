class Solution {
public:
    int search(vector<int>& nums, int target) {

        int start = 0, end = nums.size() - 1, mid;

        while (start <= end) {
            if(nums[start] <= nums[end]) {
                // this is already sorted
                return binSearch(start, end, target, nums);
            }

            mid = (start + end) / 2;

            if(nums[mid] == target) {
                // cout << "Mid is target\n";
                return mid;
            } else if(nums[start] <= nums[mid] && (target >= nums[start] && target <= nums[mid])) {
                /// this part is sorted
                return binSearch(start, mid, target, nums);
            } else if(nums[mid + 1] <= nums[end] && (target >= nums[mid + 1] && target <= nums[end])) {
                return binSearch(mid + 1, end, target, nums);
            }

            /// find the unsorted part and continue
            if(nums[start] >= nums[mid]) {
                // cout << format("Left part rotated, start: {}, end: {}\n", start, mid);
                end = mid - 1;
            } else {
                // cout << format("Right part rotated, start: {}, end: {}\n", mid, end);
                start = mid + 1;
            }
        }

        return -1;
        
    }

    int binSearch(int start, int end, int target, vector<int>& nums) {

        // cout << format("Search in [{}, {}]\n", start, end);

        auto st = begin(nums) + start, ed = begin(nums) + end;

        auto pos = lower_bound(st, ed, target);
        if(pos != std::end(nums) && *pos == target) {
            return distance(begin(nums), pos);
        } else {
            return -1;
        }
    }
};
