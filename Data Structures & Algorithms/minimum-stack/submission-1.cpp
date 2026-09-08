class MinStack {
    stack<int> stk;
    map<int, int> nums;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        nums.count(val) ? nums[val]++ : nums[val] = 1; //not checking for brevity
    }
    
    void pop() {
      
        auto pos = nums.find(stk.top());

        // cout << std::format("val: {}, count: {} \n", pos->first, pos->second);
        
        if(pos->second > 1) pos->second--;
        else nums.erase(pos);

        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return nums.begin()->first;
    }
};
