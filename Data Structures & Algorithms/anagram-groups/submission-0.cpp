class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp; 

    for ( auto c : strs ){
        string s = c;
        sort(c.begin(), c.end()); 
        mp[c].push_back(s); 
    }
    vector<vector<string>> res; 
    for( auto it : mp ){
        res.push_back(it.second);
    }
    return res; 
    }
};
