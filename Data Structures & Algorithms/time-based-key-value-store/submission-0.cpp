class TimeMap {
    unordered_map<string, vector<pair<int, string>>> nums;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        nums[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {

        auto it = nums.find(key);
        if(it == end(nums)) {
            return "";
        }

        vector<pair<int, string>>& vals = it->second;

        auto pos = lower_bound(begin(vals), end(vals), timestamp,
                    [](auto& item, int ts) {
                        return item.first < ts;
                    });

        if(pos == end(vals)) {
            return (pos - 1) >= begin(vals) ? (pos - 1)->second : "";
        } else {
            return pos->first == timestamp ? pos->second : 
                   (pos - 1) >= begin(vals) ? (pos - 1)->second : "";
        }
        
    }
};
