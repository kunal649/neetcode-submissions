class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = 0; 
        for (auto num : nums) {
            sum += num; 
        }

        if (sum % 2 != 0) { 
            return false; 
        }
        else { 
        int nsum = sum/2; 
        int dp[n + 1][nsum+ 1]; 
        for ( int i = 0; i <= n ; i++) {
            for ( int j = 0; j <= nsum; j++) {
                if ( i == 0 || j == 0) dp[i][j] = false; 
            }
        }
        dp[0][0] = true; 
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= nsum; j++) {
                if ( nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]]; 
                else 
                    dp[i][j] = dp[i-1][j]; 
            }
        }
    return dp[n][nsum]; 
        }
    }
};