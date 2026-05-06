class MinStack {
private: 
    stack<int> s; 
    stack<int> ss; 
public:
    MinStack() { }
    
    void push(int val) {
        s.push(val); 
        if ( ss.size() == 0 || ss.top() >= s.top() ) {
            ss.push(val); 
        }
    }
    
    void pop() {
        if (s.empty()) {
            return; 
        }
        int a = s.top(); 
        s.pop();  
        if (a == ss.top()) {
            ss.pop(); 
        }
    }
    
    int top() {
        if ( s.empty() ) { return -1; }
        return s.top(); 
    }
    
    int getMin() {
        if ( ss.empty() ) {
            return -1; 
        }
        return ss.top(); 
    }
};
