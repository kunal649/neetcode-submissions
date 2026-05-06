class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tCount(128, 0);
        int required = 0;
        
        for (char c : t) {
            if (tCount[c] == 0) required++;
            tCount[c]++;
        }
        
        vector<int> windowCount(128, 0);
        int formed = 0;
        int i = 0, minLen = INT_MAX, minStart = 0;
        
        for (int j = 0; j < s.size(); j++) {
            char c = s[j];
            windowCount[c]++;
            
            if (windowCount[c] == tCount[c]) {
                formed++;
            }
            
            while (formed == required) {
                if (j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    minStart = i;
                }
                
                char leftChar = s[i];
                windowCount[leftChar]--;
                if (tCount[leftChar] > 0 && windowCount[leftChar] < tCount[leftChar]) {
                    formed--;
                }
                i++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
