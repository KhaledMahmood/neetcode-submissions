class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {

        int n = temp.size(), i, j;
        vector<int> res(n, 0);

        for(i = n - 2; i >= 0; i--) {
            j = i + 1;

            while(j < n && temp[j] <= temp[i]) {
                if(res[j] == 0) {
                    // no warmer day ahead, res[i] already 0
                    j = n; 
                    break;
                } else {
                    j += res[j];
                }
            }

            if(j < n) {
                res[i] = j - i;
            }
        }

        return res;
        
    }
};
