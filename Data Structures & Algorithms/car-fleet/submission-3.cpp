class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars; 
        for ( int i = 0; i < position.size(); i++ ) {
                double time = (double)(target - position[i])/speed[i]; 
                cars.push_back({position[i], time}); 
        }
        sort(cars.begin(), cars.end()); 

        stack<double> st; 
        for ( int j = cars.size() - 1; j >= 0; j-- ) {
            if(st.empty() || cars[j].second > st.top()) {
                st.push(cars[j].second); 
            }
        }
    return st.size();  
    }
};
