class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        int v = 0, x,y;
        std::priority_queue<int> pq(stones.begin(), stones.end());

        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();

            y = pq.top();
            pq.pop();

            v = abs(x - y);

            if (v > 0) pq.push(v);
            
        }

        return pq.empty() ? 0 : pq.top();
        
    }
};
