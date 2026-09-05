class Solution {
public:
    int climbStairs(int n) {

        unordered_map<int, int> memo = {{0, 0},{1, 1}, {2, 2}};

        return calcStep(n, memo);        
    }

    int calcStep(int n, unordered_map<int, int>& memo) {

        if(memo.find(n) != memo.end()) return memo[n];
        
        memo[n] = calcStep(n-1, memo) + calcStep(n-2, memo);
        return memo[n];
    }


};
