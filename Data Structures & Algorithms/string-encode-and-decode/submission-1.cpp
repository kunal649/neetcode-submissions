class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (auto& s : strs) {
            result += to_string(s.size()) + "#" + s; 
        }
        return result;
    }

    vector<string> decode(string s) {
    vector<string> result; 
    int i = 0; 
    while (i < s.size()) {
        // keep track of new iterator
        int j = i; 
        // finding the delimiter
        while ( s[j] != '#' ) { j++; }
        // convert length find into integer 
        int length = stoi(s.substr(i, j - i)); 
        // find the word that must exists after # 
        result.push_back(s.substr(j + 1,length)); 
        i = j + 1 + length; 
    }
    return result; 
    }
};
