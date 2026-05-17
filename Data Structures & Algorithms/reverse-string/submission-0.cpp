class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(); 
        int i = 0; 
        int j = n - 1; 

        while ( i < j) {
            char a = s[i]; 
            char b = s[j]; 
            s[i] = b; 
            s[j] = a; 
            i++; 
            j--; 
        }
    }
};