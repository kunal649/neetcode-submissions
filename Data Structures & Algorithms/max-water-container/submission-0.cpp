class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int left = 0; 
        int right = n - 1; 
        int a = 0; int ans = 0; 
    while ( left < right ) {
        int l = heights[left]; 
        int r = heights[right]; 

        a = min(heights[left], heights[right]) * (right - left); 
        ans = max(ans, a); 

        if (l < r) { left++; }
        else {
            right--; 
     }

    }
    return ans; 
    }
};
