class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp; 
        int n = nums.size(); 

        for (auto& e : nums) {
            mp[e]++;
        }

        vector<vector<int>> bucket(n + 1);
        for (auto& it : mp) {
            int freq = it.second;
            int value = it.first; 
            bucket[freq].push_back(value); 
        }
        
        vector<int> result; 
        for (int i = n; i >= 0 && result.size() < k; i--) {
            for (auto& e : bucket[i]) {
                result.push_back(e); 
            }
            if ( result.size() == k) break; 
        }
        return result; 
    }
};
