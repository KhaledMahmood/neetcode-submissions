class Solution {

    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {

        vector<int> combi;

        sort(begin(candi), end(candi));

        process(target, 0, candi, combi);

        return res;
    }

private:
    void process(int target, int idx, vector<int>& candi, vector<int>& combi) {

        if(target < 0) {
            return;
        }

        if(target == 0) {
            res.push_back(combi);
            return;
        }

        for(int i = idx; i < candi.size(); ++i) {
            
            combi.push_back(candi[i]);
            process(target - candi[i], i + 1, candi, combi);
            combi.pop_back();

            while((i + 1) < candi.size() && candi[i] == candi[i+1]) {
                ++i;
            }
        }

    }
};
