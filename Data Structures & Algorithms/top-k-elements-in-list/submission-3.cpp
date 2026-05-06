class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int, int> mp; 
        for ( auto& c : nums ) {
            mp[c]++; 
        }

        vector<vector<int>> bucket(n+1); 
        for (auto& it : mp) {
            int freq = it.second; 
            int value = it.first; 

            bucket[freq].push_back(value); 
        }

        vector<int> ans; 
        for (int j = n; j >= 0 && ans.size() < k; j--) {
            for ( auto& x : bucket[j] ) {
                ans.push_back(x); 
            }
            if ( ans.size() == k ) break; 
        }
    return ans; 
    }
};
