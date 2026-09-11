class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newVal) {

        int i;
        int n = intervals.size();

        vector<vector<int>> res;

        if(n == 0) {
            return {newVal};
        }

        i = 0;
        while((i < n) && intervals[i][1] < newVal[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        if(i == n) {
            // push back
            intervals.push_back(newVal);
            return intervals;
        } else if(newVal[1] < intervals[i][0]) {
            // no overlap, insert at i
            intervals.insert(intervals.begin()+i, newVal);
            return intervals;            
        } else {
            /// newVal overlapped with i at start
            // update i
            intervals[i][0] = min(intervals[i][0], newVal[0]);

            if(newVal[1] <= intervals[i][1]) {
                /// new end inside i end, return
                return intervals;
            }

            intervals[i][1] = newVal[1];
        }

        auto it = intervals.begin() + i + 1;
        while(it < intervals.end()) {
            if((*it)[1] <= intervals[i][1]) {
                // it inside i
                it++;
                //it = intervals.erase(it);
            } else if(intervals[i][1] >= (*it)[0]) {
                // merge i and it, set new end
                intervals[i][1] = (*it)[1];
                //it = intervals.erase(it);
                it++;
            } else {
                break;
            }
        }

        res.push_back(intervals[i]);
        while(it < intervals.end()) {
            res.push_back(*it);
            it++;
        }

        return res;
    }
};
