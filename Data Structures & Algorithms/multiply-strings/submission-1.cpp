class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0") return "0";

        string res;
        for(int i = num2.size()-1, pass = 0; i >= 0; i--, pass++) {

            string v = mul(num1, int(num2[i] - '0'));

            for(int p = 1; p <= pass; p++) {
                v += '0';
            }

            res = add(res, v);
        }

        return res;
        
    }

    string mul(string num, int n) {

        int carry = 0, val;
        string res;

        for(int i = num.size() - 1; i >= 0; i--) {
            val = (int(num[i] - '0') * n) + carry;
            res.insert(res.begin(), char(val%10 + '0'));
            carry = val/10;
        }

        if(carry) {
            res.insert(res.begin(), char(carry + '0'));
        }

        return res;
    }

    string add(string s1, string s2) {
        int carry = 0, v;
        string res;

        if(s1.size() < s2.size()) s1.swap(s2); // smallest in s2

        for(int i = s1.size()-1, j = s2.size() -1; i >=0; i--, j--) {
            v = int(s1[i] - '0') + (j>=0 ? int(s2[j] - '0') : 0) + carry;
            s1[i] = char(v%10 + '0');
            carry = v/10;
        }

        if(carry) {
            s1.insert(s1.begin(), char(carry + '0'));
        }

        return s1;
    }
};
