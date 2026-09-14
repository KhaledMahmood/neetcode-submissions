class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int dup = 0;
        set<int> visit = {};

        for(auto& i: nums) {
            if(visit.count(i)) {
                dup = i;
                break;
            }
            visit.insert(i);
        }

        return dup;
        
    }
};