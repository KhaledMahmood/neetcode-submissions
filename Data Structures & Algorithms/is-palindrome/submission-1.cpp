class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() -1;

        while(i < j) {
            while(!isalnum(s[i]) && i < s.size()) {
                ++i;
            }
            while(!isalnum(s[j]) && j >= 0) {
                --j;
            }
 
            if(i > j) return true;

            if(tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                i++;
                j--;
            }
        }

        return true;
    }
};
