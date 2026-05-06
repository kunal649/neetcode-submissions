class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int left = 0; 
        int right = n - 1; 
        int ans = 0; 

    while ( left < right ) {

        int a = min(heights[left], heights[right]) * (right - left); 
        ans = max(ans, a); 

        if (heights[left] < heights[right] ) { left++; }
        else {
            right--; 
     }

    }
    return ans; 
    }
};
