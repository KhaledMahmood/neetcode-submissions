class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> info;

        for(int i = 0; i < position.size(); ++i) {
            info.push_back({position[i], speed[i]});
        }

        sort(info.rbegin(), info.rend());

        int fleet = 1;
        double currTime, prevTime = double (target - info[0].first) / info[0].second;

        for(auto [pos, spd]: info) {
            currTime = double(target - pos) / spd;

            if(currTime > prevTime) {
                prevTime = currTime;
                ++fleet;
            }
        }

        return fleet;
    }
};
