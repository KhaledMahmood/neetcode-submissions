class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size(), cols = matrix[0].size();
        set<int> zRows, zCols;

        for(int i = 0; i < rows; i++) {
            for(int j = 0 ; j < cols; j++) {
                if(matrix[i][j] == 0) {
                    zRows.insert(i);
                    zCols.insert(j);
                } 
            }
        }

        for (auto& r: zRows) {
            for(int j = 0; j < cols; j++) {
                matrix[r][j] = 0;
            }
        }

        for(auto& c: zCols) {
            for(int i = 0; i < rows; i++) {
                matrix[i][c] = 0;
            }
        }
        
    }
};
