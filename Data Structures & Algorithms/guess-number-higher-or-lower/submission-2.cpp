/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {


        int min = 1, max = n, mid, res;

        while(min <= max) {
            mid = (min + max)/2;
            res = guess(mid);

            // cout << format("min: {}, max: {}, mid: {}, res: {}\n", min, max, mid, res);

            if(res == 0) break;
            else if (res == -1) {
                max = mid - 1;
            } else {
                min = mid + 1;
            }
        }

        return mid;
    }
};