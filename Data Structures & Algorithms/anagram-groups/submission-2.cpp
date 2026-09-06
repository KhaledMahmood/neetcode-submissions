class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> sorted;
        for(const auto& s: strs) {
            string ssrt = s;
            sort(ssrt.begin(), ssrt.end());
            sorted[ssrt].push_back(s);
        }

        vector<vector<string>> grps;
        for(auto& p: sorted) {
            grps.push_back(p.second);
        } 

        return grps;
        
    }
};
