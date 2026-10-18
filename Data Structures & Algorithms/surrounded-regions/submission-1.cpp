class Solution {

    int rows, cols;

    vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    set<pair<int, int>> visits;

public:
    void solve(vector<vector<char>>& board) {

        rows = board.size();
        cols = board[0].size();

        for(int r = 0; r < rows; ++r) {
            if(board[r][0] == 'O' && !visits.contains({r, 0})) {
                fill(r, 0, board);
            }

            if(cols > 1 && board[r][cols-1] == 'O' && !visits.contains({r, cols-1})) {
                fill(r, cols-1, board);
            }
        }

        for(int c = 1; c < cols-1; ++c) {
            if(board[0][c] == 'O' && !visits.contains({0, c})) {
                fill(0, c, board);
            }

            if((rows > 1) && (board[rows-1][c] == 'O') && !visits.contains({rows-1, c})) {
                fill(rows-1, c, board);
            }
        }

        for(int r = 0; r < rows; ++r) {
            for(int c = 0; c < cols; ++c) {
                if(!visits.contains({r, c}) && board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
            }
        }
    }

    void fill(int r, int c, vector<vector<char>>& board) {

        queue<pair<int,int>> q;
        q.push({r,c});

        while(!q.empty()) {
            auto [qr, qc] = q.front();
            q.pop();

            r = qr;
            c = qc;

            visits.insert({r, c});

            for(int i = 0; i < 4; ++i) {
                auto& [dr,dc] = directions[i];
                int nr = r + dr, nc = c + dc;

                if(clamp(nr, 0, rows-1) == nr && clamp(nc, 0, cols-1) == nc && 
                board[nr][nc] == board[r][c] && !visits.contains({nr, nc})) {
                    q.push({nr, nc});
                }
            }
        }
    }
};
