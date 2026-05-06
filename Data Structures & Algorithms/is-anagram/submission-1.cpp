class Solution {
public:
    bool isAnagram(string s, string t) {
    if ( s.size() != t.size() ) { return false;}

    vector<int> check(26, 0); 
    for (int i = 0; i < s.length() ; i++) {
        check[s[i] - 'a']++; 
        check[t[i] - 'a']--;
    }
    
    for (int val : check ){
        if ( val != 0) {
            return false;
        }
    }
    return true; 
    }
};
