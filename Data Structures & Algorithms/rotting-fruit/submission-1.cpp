class Solution {
    int rows, cols;
public:
    int orangesRotting(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        int fresh = 0;
        int secs = 0;
        queue<pair<int, int>> q;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == 1) {
                    ++fresh;
                } else if(grid[r][c] == 2) {
                    q.push({r,c});
                }
            }
        }

        while(fresh > 0 && !q.empty()) {
            int l = q.size();
            while(l-- > 0) {
                auto [r, c] = q.front();
                q.pop();

                if(r - 1 >= 0 && grid[r-1][c] == 1) {
                    q.push({r-1,c});
                    grid[r-1][c] = 2;
                    --fresh;
                }

                if(r + 1 < rows && grid[r+1][c] == 1) {
                    q.push({r+1,c});
                    grid[r+1][c] = 2;
                    --fresh;
                }

                if(c - 1 >= 0 && grid[r][c-1] == 1) {
                    q.push({r,c-1});
                    grid[r][c-1] = 2;
                    --fresh;
                }

                if(c + 1 < cols && grid[r][c+1] == 1) {
                    q.push({r,c+1});
                    grid[r][c+1] = 2;
                    --fresh;
                }
            }

            ++secs;
        }

        return fresh > 0 ? -1 : secs;
        
    }
};
