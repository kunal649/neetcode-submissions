class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int dp[n]; 
    dp[0] = nums[0]; 

    int i = 1; 
    while (i < n) { 
        dp[i] = max(nums[i], nums[i] + dp[i-1]); 
        i++; 
    }
    
    int ans = INT_MIN; 
    for (auto d : dp) {
        ans = max(d, ans); 
    }
    return ans; 
    }
};
