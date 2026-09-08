class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        vector<int> res (temp.size(), 0); //fill with 0
        stack<pair<int, int>> vis;

        for(int t = 0; t < temp.size(); t++) {
            while(!vis.empty()) {
                auto [tmp, pos] = vis.top();
                if(tmp < temp[t]) {
                    res[pos] = t - pos;
                    vis.pop();
                } else {
                    break;
                }
            }

            vis.push({temp[t], t});
        }

        return res;        
    }
};
