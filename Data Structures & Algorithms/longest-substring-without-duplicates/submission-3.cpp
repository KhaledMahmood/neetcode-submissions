class Solution {

public:
    int lengthOfLongestSubstring(string s) {

        int maxLen = 0, left = 0;
        unordered_map<char, int> lastIdx;

        for(int i = 0; i < s.size(); ++i) {

            auto pos = lastIdx.find(s[i]);
            if(pos != end(lastIdx)) {
                left = max(left, lastIdx[s[i]] + 1);
            } 

            lastIdx[s[i]] = i;
            maxLen = max(maxLen, i - left + 1);
        }

        return maxLen;
        
    }
};
