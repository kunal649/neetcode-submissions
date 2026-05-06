class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0; 
        int j = 1; 
        int n = prices.size(); 
        int ans = 0; int profit = 0; int buy = INT_MAX; 

    while ( j < n ) {
        if ( prices[j] < prices[i] ) {
            i = j; 
        }
        else {
             profit = prices[j] - prices[i];
        }
        ans = max(ans, profit); 
        j++; 
    }
    return ans; 
    }
};
