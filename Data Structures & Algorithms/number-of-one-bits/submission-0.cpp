class Solution {
public:
    int hammingWeight(uint32_t n) {

        uint32_t c = 0;
        
        while (n > 0) {
            c += (n & 0x1);
            n >>= 1;
        }

        return c;

    }
};
