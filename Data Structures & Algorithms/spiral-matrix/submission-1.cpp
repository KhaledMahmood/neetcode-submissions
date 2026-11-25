class Solution {
    vector<int> res = {};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int i = 0, j = 0, m = matrix.size(), n = matrix[0].size();

        while (i < m && j < n) {

            getSpiral(i, j, m-1, n-1, matrix);

            i++;
            j++;
            m--;
            n--;
        }

        return res;
        
    }

    void getSpiral(int i, int j, int m, int n, vector<vector<int>>& mat) {

        int r = i, c = j;

        // left to right
        while(c <= n) {
            res.push_back(mat[r][c]);
            c++;
        }

        c = n;
        r++;
        while(r <= m) {
            res.push_back(mat[r][c]);
            r++;
        }
        
        if(i < m && j < n) {
            r = m;
            c--;
            while(c > j) {
                res.push_back(mat[r][c]);
                c--;
            }

            while(r > i) {
                res.push_back(mat[r][c]);
                r--;
            }
        }
    }
};
