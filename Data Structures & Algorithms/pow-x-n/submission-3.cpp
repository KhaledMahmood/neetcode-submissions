class Solution {
public:
    double myPow(double x, int n) {

        if(x == 0.0L) return 0.0L;

        double res = getPow(x, abs(n));
        
        return n >= 0 ? res : 1.000/res;
        
    }

    double getPow(double x, int n) {

        if(n == 0) {
            return 1;
        } else if(n == 1) {
            return x;
        }

        double res = getPow(x, n/2);
        return res * res * ((n % 2) ? x : 1);
    }

};
