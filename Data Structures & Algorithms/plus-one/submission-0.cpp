class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        bool carry = true; //think adding 1 as carry
        for(auto i = digits.rbegin(); i < digits.rend(); i++) {
            if (carry) (*i)++;
            if(*i == 10) {
                carry = true;
                *i = 0;
            } else {
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
