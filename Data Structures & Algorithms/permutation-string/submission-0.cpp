class Solution {
public:
    bool checkInclusion(string s1, string s2) {

    int i = 0;
    int n = s2.size(); 

    unordered_map<char, int> mp; 
    for (auto &c : s1) {
        mp[c]++;
    }

    unordered_map<char, int> windowMap; 
    
    for ( int j = 0; j < n; j++ ) { 
        windowMap[s2[j]]++; 

        if ( j - i + 1 > s1.size()) {
            windowMap[s2[i]]--; 
             if ( windowMap[s2[i]] == 0) {
                windowMap.erase(s2[i]); 
            }
        i++; 
        }

        if ( j - i + 1 == s1.size()) {
            if ( windowMap == mp ) {
                return true; 
            }
        }
    }
    return false; 
    }
};
