class Solution {
    int rows, cols, maxArea = 0;

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == 1) {
                    maxArea = max(maxArea, fill(r, c, grid));
                }
            }
        }

        return maxArea;
    }

    int fill(int r, int c, vector<vector<int>>& grid) {
        // if((clamp(r, 0, rows) != r) || (clamp(c, 0, cols) != c) ||
        //  grid[r][c] == 0) {
        //     return 0;
        // }

        int area = 1;
        grid[r][c] = 0;

        if(r - 1 >= 0 && grid[r-1][c] == 1) {
            area += fill(r-1, c, grid);
        }

        if(r + 1 < rows && grid[r+1][c] == 1) {
            area += fill(r+1, c, grid);
        }

        if(c - 1 >= 0 && grid[r][c-1] == 1) {
            area += fill(r, c-1, grid);
        }

        if(c + 1 < cols && grid[r][c+1] == 1) {
            area += fill(r, c+1, grid);
        }

        return area;
    }
};
