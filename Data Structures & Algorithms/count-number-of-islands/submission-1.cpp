class Solution {
    int count = 0;
    int rows, cols;
public:
    int numIslands(vector<vector<char>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == '1') {
                    ++count;
                    fill(r, c, grid);
                }
            }
        }

        return count;
    }

private:
    void fill(int r, int c, vector<vector<char>>& grid) {

        // if(clamp(r, 0, rows) != r || clamp(c, 0, cols) != c) {
        //     return;
        // }

        if(grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '-';

        if((r - 1 >= 0 && grid[r-1][c] == '1')) {
            fill(r - 1, c, grid);
        }

        if((r + 1 < rows && grid[r+1][c] == '1')) {
            fill(r + 1, c, grid);
        }
        
        if((c - 1 >= 0 && grid[r][c-1] == '1')) {
            fill(r, c - 1, grid);
        }

        if(c + 1 < cols && grid[r][c + 1] == '1') {
            fill(r, c + 1, grid);
        }
    }
};
