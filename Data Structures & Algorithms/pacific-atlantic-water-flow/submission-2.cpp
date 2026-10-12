class Solution {
    int rows, cols;
    set<pair<int, int>> pac, atl;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {

        rows = h.size();
        cols = h[0].size();

        for(int r = 0; r < rows; ++r) {
            process(r, 0, pac, h);
            process(r, cols-1, atl, h);
        }

        for(int c = 0; c < cols; ++c) {
            process(0, c, pac, h);
            process(rows-1, c, atl, h);
        }

        vector<vector<int>> res;

        for(auto [r, c]: pac) {
            if(atl.contains({r,c})) {
                res.push_back({r,c});
            }
        }

        return res;
    }

    void process(int r, int c, set<pair<int, int>>& conn, vector<vector<int>>& h) {

        conn.insert({r,c});
            
        for(auto& [dr, dc]: dir) {
            int nr = r + dr, nc = c + dc;

            if(clamp(nr, 0, rows-1) == nr && clamp(nc, 0, cols-1) == nc && 
                h[nr][nc] >= h[r][c] && !conn.contains({nr, nc})) {
                process(nr, nc, conn, h);
            }
        }
    }
};
