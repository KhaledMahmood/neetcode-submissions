class CountSquares {

    map<pair<int, int>, int> pts;

public:
    CountSquares() {

    }
    
    void add(vector<int> point) {
        pts[{point[0], point[1]}]++;      
    }
    
    int count(vector<int> p) {
        int res = 0;

        for(auto& [xy, freq]: pts) {
            auto [x, y] = xy;
            if(abs(x - p[0]) == abs(y - p[1]) && p[0] != x && p[1] != y) {
                res += pts[{x, p[1]}] * pts[{p[0], y}] * pts[{x,y}];
            }
        }

        return res;
        
    }
};
