class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        char dig;
        unordered_map<char, vector<pair<int, int>>> dict;

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                dig = board[i][j];

                if('.' == dig) continue;

                if(dict.count(dig) && checkDup(i , j, dict[dig]))
                    return false;
                
                dict[dig].push_back({i,j});
                
            }
        }

        // for(auto [k,v]: dict) {
        //     cout << k;
        //     for(auto [i,j]: v) {
        //         cout << "[" << i << "," << j << "]";
        //     }
        //     cout << "\n";
        // }

        return true;
        
    }

    bool checkDup(int r, int c, vector<pair<int, int>>& coord) {

        int subI = int(r/3)*3, subJ = int(c/3)*3;
        int subK = subI+3, subL = subJ + 3;

        for(auto [rr, cc]: coord) {
            if(r == rr || c == cc) {
                // cout << "RowCol >>>" << "Pos: [" << r << "," << c << "], match: " << rr << "," << cc ;
                return true; //duplicate
            }
            else if((rr >= subI && rr < subK) && (cc >= subJ && cc < subL)) 
            {
                // cout << "SubMat >>>" << "Pos: [" << r << "," << c << "], match: " << rr << "," << cc;
                // cout << " [" << subI << "," << subJ << "," << subK << "," << subL << "]";
                return true;
            }
        }

        return false;
    }
};
