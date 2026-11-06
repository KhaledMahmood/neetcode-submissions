class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int min = 1, max = *max_element(begin(piles), end(piles));
        int k, res = max;

        uint64_t totalTimes = 0;

        while (min <= max) {
            k = (min + max) / 2;

            totalTimes = 0;
            for(int p: piles) {
                totalTimes += ceil(double(p)/double(k));
            }

            if(totalTimes <= h) {
                res = k;
                max = k - 1;
            } else {
                min = k + 1;
            }
        }

        return res;
    }
};