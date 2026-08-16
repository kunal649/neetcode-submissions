class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size(); 
        vector<int> dp(amount + 1,  INT_MAX); 
        dp[0] = 0;  
         for (int c = 0; c < n; c++) {
                for ( int i = coins[c]; i <= amount ; i++) {
                    if ( dp[i - coins[c]] != INT_MAX) {
                            dp[i] = min(dp[i],  dp[i - coins[c]] + 1);
                    }    
                }
        } 
    return dp[amount] == INT_MAX ? -1 : dp[amount]; 
    }
};
