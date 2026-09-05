class Solution {
public:
    bool isValid(string s) {

        std::stack<char> stk;

        for(const auto& c: s) {
            if(c == '(' || c=='{' || c=='[') stk.push(c);
            else if(c == ')') {
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else return false;
            } else if(c == '}') {
                if(!stk.empty() && stk.top() == '{') stk.pop();
                else return false;
            } else if(c == ']') {
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else return false;
            }
        }

        return stk.empty();
        
    }
};
