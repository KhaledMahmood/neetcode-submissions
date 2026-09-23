class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> expr;
        int x, y;

        for(auto& t: tokens) {

            if(t == "+" || t == "-" || t == "*" || t == "/") {

                y = stoi(expr.top());
                expr.pop();
                x = stoi(expr.top());
                expr.pop();

                if(t == "+") {
                    expr.push(to_string(x + y));
                } else if(t == "-") {
                    expr.push(to_string(x - y));
                } else if (t == "*") {
                    expr.push(to_string(x * y));
                } else {
                    expr.push(to_string(x / y));
                }
            } else {
                expr.push(t);
            }
        }

        return stoi(expr.top());
        
    }
};
