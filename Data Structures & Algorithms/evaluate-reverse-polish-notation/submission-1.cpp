class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        unordered_map<string, function<int (int, int)>> mp = {
            {"+", [](int a, int b){return a+b;}}, 
            {"-", [](int a, int b){return a-b;}}, 
            {"*", [](int a, int b){return (long)a*(long)b;}}, 
            {"/", [](int a, int b){return a/b;}}
        }; 

        for (auto& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
               int b = st.top();
               st.pop();  
               int a = st.top(); 
               st.pop();
               int ans = mp[c](a,b); 
               st.push(ans); 
            }
            else {
                st.push(stoi(c));
            }
        }
    return st.top(); 
    }
};
