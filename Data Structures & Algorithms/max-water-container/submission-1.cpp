class Solution {
public:
    int maxArea(vector<int>& heights) {

        int i, j, last;
        uint64_t max = 0, wat;
        for(i = 0; i < heights.size(); i++) {
            last = 0;
            for(j = heights.size() - 1; j > i; j--) {
                wat = (j-i) * min(heights[i], heights[j]);
                if(wat > max) {
                    max = wat;
                    last = i + (max / heights[i]);
                }

                // cout << "i: " << heights[i] << ", " << heights[j] << ", wat: " << wat << ", max: " << max << endl; 

                if(heights[j] >= heights[i]) break;
                if(j < last) break;
            }
        }

        return max;
        
    }
};
