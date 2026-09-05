class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_set<int> visit;
        for(const auto& n: nums) {
            if(visit.contains(n)) return true;
            else visit.insert(n);
        }

        return false;
        
    }
};