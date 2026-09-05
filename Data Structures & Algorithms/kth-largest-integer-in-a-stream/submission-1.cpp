class KthLargest {
    priority_queue<int, vector<int>, greater<int>> n;
    int k;
public:
    KthLargest(int kk, vector<int>& nums): k(kk), n(nums.begin(), nums.end()) {
        while(n.size() > k) {
            n.pop();
        }
    }
    
    int add(int val) {
        n.push(val);
        if(n.size() > k) n.pop();

        return n.top();
    }

    // int getPos(int val, int beg, int end) {

    //     if(end == beg) return n[beg] >= val ? beg : beg + 1;

    //     int mid = ((beg+end)/2);
    //     if(n[mid] > val) {
    //         return getPos(val, beg, mid-1);
    //     } else if(n[mid] < val) {
    //         return getPos(val, mid+1, end);
    //     } else {
    //         return mid;
    //     }
    // }
};
