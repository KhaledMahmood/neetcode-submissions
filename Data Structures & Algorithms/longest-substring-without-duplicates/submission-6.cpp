class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int left = 0, right, len = 0;
        unordered_set<char> unq;

        for(right = 0; right < s.size(); ++right) {
            while(unq.find(s[right]) != end(unq)) {
                unq.erase(s[left]);
                ++left;
            }

            unq.insert(s[right]);
            len = max(len, right - left + 1);
        }

        return len;
        
    }
};
