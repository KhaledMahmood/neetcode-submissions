class Solution {

    int len;
    vector<string> res;

public:
    vector<string> generateParenthesis(int n) {
        len = n;

        process("", 0, 0);

        return res;
    }

private:
    void process(string s, int openBr, int closeBr) {

        if(closeBr > openBr) {
            return;
        }

        if((s.size() == 2*len)) {
            if((closeBr == openBr) && openBr == len) {
                res.push_back(s);
            } 
            
            return;
        }

        if(openBr < len) {
            process(s + "(", openBr+1, closeBr);
        }
        
        if(closeBr < openBr) {
            process(s + ")", openBr, closeBr + 1);
        }
        
    }

};
