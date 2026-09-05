class Solution {
public:
    int singleNumber(vector<int>& n) {
        /*std::sort(n.begin(), n.end());

        auto i = n.begin();
        while(i < n.end()-1) {
            if(*i == *(i+1)) i += 2;
            else break;
        }

        return *i; */

        long res = 0;
        for(const auto& v: n) res ^= v;

        return res;
        
    }
};
