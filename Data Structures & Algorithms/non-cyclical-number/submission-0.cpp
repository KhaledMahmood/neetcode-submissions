class Solution {
public:
    bool isHappy(int n) {

        std::set<int> happ = {};

        long sum = 0;
        while (n != 1) {
            
            sum = makeSum(n);

            if(happ.contains(sum)) {
                return false;
            }

            happ.insert(sum);
            n = sum;
        }

        return true;            
        
    }

    long makeSum(int nn) {
        if (nn == 10 || nn == 100 || nn == 1000) return 1;
        long sum = 0;
        while(nn > 0) {
            sum += (nn%10) * (nn%10);
            nn /= 10;
        }
        return sum;
    }
};
