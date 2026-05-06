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
        int left = 0; 
        while (left < n) {
            int mid = left + (n - left)/ 2; 
            int ans = guess(mid); 
        if ( ans == 0) {
            return mid; 
        }  
        else if ( ans == 1 ) {
            left = mid + 1; 
        }
        else {
            n = mid - 1; 
        }
        }
    }
};