class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        const int rows = matrix.size(), cols = matrix[0].size();

        int start = 0, end = rows - 1;

        while(start <= end) {
            int mid = (start + end) / 2;

            if(target >= matrix[mid][0] && (target <= matrix[mid][cols - 1])) {
                return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
            }

            if(target < matrix[mid][0]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return false;
        
    }
};
