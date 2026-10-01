class Solution {

    const int INF = 2147483647;

    int rows, cols;
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        rows = grid.size();
        cols = grid[0].size();

        queue<pair<int, int>> q;

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(grid[r][c] == 0) {
                    q.push({r,c});
                }
            }
        }

        int dist = 1;

        while(!q.empty()) {
            int len = q.size();

            while(len-- > 0) {

                auto [r, c] = q.front();
                q.pop();

                if(r - 1 >= 0 && grid[r-1][c] == INF) {
                    grid[r-1][c] = dist;
                    q.push({r-1, c});
                }

                if(r + 1 < rows && grid[r+1][c] == INF) {
                    grid[r+1][c] = dist;
                    q.push({r+1, c});
                }

                if(c - 1 >= 0 && grid[r][c-1] == INF) {
                    grid[r][c-1] = dist;
                    q.push({r, c-1});
                }

                if(c + 1 < cols && grid[r][c+1] == INF) {
                    grid[r][c+1] = dist;
                    q.push({r, c+1});
                }
            }

            ++dist;
        }

    }
};
