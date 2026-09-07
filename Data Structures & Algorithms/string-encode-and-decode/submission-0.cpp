class Solution {
public:

    string encode(vector<string>& strs) {

        string res;
        for(auto& s: strs) {
            res += getLen(s);
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {

        int i = 0, len;
        vector<string> res;

        while (i < s.size()) {
            len = stoi(s.substr(i, 3));
            i += 3;

            res.push_back(s.substr(i, len));
            i += len;
        }

        return res;
    }

    string getLen(string s) {
        char len[6];
        sprintf(len, "%03zu\0", s.size());
        return len;
    }
};
