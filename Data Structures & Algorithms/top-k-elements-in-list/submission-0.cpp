class Solution {
public:
    typedef pair<int, int> p; 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for ( int &n : nums) { mp[n]++; }

        priority_queue<p, vector<p>, greater<p>> heap; 

        for (auto &it : mp) {
            int value = it.first;
            int freq = it.second; 

            heap.push({freq, value}); 
            if ( heap.size() > k) {
                heap.pop(); 
            }
        }

        vector<int> res;
        while(!heap.empty()) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res; 
    }
};
