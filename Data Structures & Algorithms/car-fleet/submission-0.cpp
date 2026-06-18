class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,double>> car(n);
        for(int i = 0; i<n;i++){
           double time = double(target - position[i]) / speed[i];
            car[i]={position[i],time};
        }
        sort(car.rbegin(),car.rend());
        stack<double> st;
        for(int i = 0; i<n;i++){
            double currentTime = car[i].second;
            if (st.empty() || currentTime > st.top()) {
                st.push(currentTime);
            }
            
        }
        return st.size();
    }
};