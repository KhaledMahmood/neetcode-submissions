class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> mapS, mapT;

        for(auto& c: s) {
            mapS[c]++;
        }

        for(auto& c: t) {
            mapT[c]++;
        }

        return mapS == mapT;
         
    }
};
