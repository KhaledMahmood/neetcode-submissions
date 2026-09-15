class LRUCache {

    unordered_map<int, int> idMap;
    map<pair<int, int>, int> kvMap;

    int idx, cap;

public:
    LRUCache(int capacity): idx(0), cap(capacity) {
        
    }
    
    int get(int key) {
        
        if(auto pos = idMap.find(key); pos != idMap.end()) {
            int oldId = pos->second;
            pos->second = ++idx;

            int value = kvMap[{oldId, key}];

            // cout << format("GET updating [{}, {}] id from {} to {}\n", key, value, oldId, idMap[key]);

            kvMap.erase({oldId, key});

            kvMap[{idx, key}] = value;

            return value;
        }

        return -1;
        
    }
    
    void put(int key, int value) {
    
        if(idMap.count(key)) {
            int oldId = idMap[key];
            kvMap.erase({oldId, key});
        }

        ++idx;
        idMap[key] = idx;
        kvMap[{idx, key}] = value;       

        if(kvMap.size() > cap) {
            auto pos = kvMap.begin();
            // cout << format("Removing key {}, value: {}\n", pos->first.second, pos->second);
            idMap.erase(pos->first.second);
            kvMap.erase(pos);
        }
        
    }
};
