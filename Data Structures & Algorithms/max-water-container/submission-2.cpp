class Solution {
public:
    int maxArea(vector<int>& heights) {

        int i = 0, j = heights.size() -1, max = 0, wat;

        while(i<j) {
            wat = min(heights[i], heights[j]) * (j-i);

            if(max < wat) max = wat;

            if(heights[j] < heights[i]) {
                j--;
            } else {
                i++;
            }
        }

        return max;
        
    }
};
