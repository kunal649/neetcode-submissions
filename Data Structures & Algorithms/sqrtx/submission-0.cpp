class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int r = x; int ans = 0; 

    while ( left <= r ) {
        int mid = left + (r - left)/2; 

        if ( (long long)mid * mid == x ) {
            return mid; 
        }
        else if ( (long long)mid * mid > x) {
            r = mid - 1;
        }
        else {
            left = mid + 1; 
            ans = mid; 
        }
    }
    return ans; 
    }
};