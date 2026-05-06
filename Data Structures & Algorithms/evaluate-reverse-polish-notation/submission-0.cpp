class Solution {
private: 
    int Operate(int a, int b, string token) {
    if ( token == "+" ) {
        return a+b; 
    }
    if ( token == "*" ) {
        return a*b; 
    }
    if ( token == "-" ) {
        return a-b; 
    }
    if ( token == "/" ) {
        return a/b; 
    }
    return -1; 
}
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        
        for (auto& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
               int b = st.top();
               st.pop();  
               int a = st.top(); 
               st.pop();
               int ans = Operate(a, b, c); 
               st.push(ans); 
            }
            else {
                st.push(stoi(c));
            }
        }
    return st.top(); 
    }
};
