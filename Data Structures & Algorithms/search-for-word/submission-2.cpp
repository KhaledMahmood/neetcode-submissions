class Solution {
    string w;
    int rows, cols;
public:
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        rows = board.size();
        cols = board[0].size();

        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(process(board, {board[i][j]}, i, j, {{i,j}})) {
                    return true;
                }
            }
        }

        return false;
        
    }

    bool process(vector<vector<char>>& board, string s, int i, int j, set<pair<int,int>> visit) {

        if(s == w) {
            return true;
        }

        if(s.size() >= w.size()) {
            return false;
        }

        visit.insert({i,j});

        if((j + 1 < cols) && !visit.contains({i, j+1}) && process(board, s + board[i][j+1], i, j+1,  visit)) {
            return true;
        }

        if((j - 1 >= 0) && !visit.contains({i, j-1}) && process(board, s + board[i][j-1], i, j-1, visit)) {
            return true;
        }

        if((i + 1 < rows) && !visit.contains({i + 1, j}) && process(board, s + board[i + 1][j], i + 1, j, visit)) {
            return true;
        }

        if((i - 1 >= 0) && !visit.contains({i - 1, j}) && process(board, s + board[i - 1][j], i - 1, j, visit)) {
            return true;
        }

        return false;
    }
};
