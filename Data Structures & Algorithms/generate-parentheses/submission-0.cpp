class Solution {

    int len;
    vector<string> res;

public:
    vector<string> generateParenthesis(int n) {
        len = 2 * n;

        process("", 0, 0);

        return res;
    }

private:
    void process(string s, int openBr, int closeBr) {

        if(closeBr > openBr) {
            return;
        }

        if(abs(openBr-closeBr) > (len - s.size())) {
            return;
        }

        if((s.size() == len)) {
            if((closeBr == openBr)) {
                res.push_back(s);
            }
            
            return;
        }

        process(s + "(", openBr+1, closeBr);
        process(s + ")", openBr, closeBr + 1);
    }

};
