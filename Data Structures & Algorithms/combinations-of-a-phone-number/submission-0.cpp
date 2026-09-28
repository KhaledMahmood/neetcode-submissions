class Solution {

    vector<string> res;
    map<char, string> charMap = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};
    
public:
    vector<string> letterCombinations(string digits) {

        if(digits == "") return res;

        process(0, digits, "");

        return res;
        
    }

    void process(int i, string& dig, string s) {

        if(i == dig.size()) {
            res.push_back(s);
            return;
        }

        for(auto& c: charMap[dig[i]]) {
            process(i+1, dig, s + c);
        }

    }
};
