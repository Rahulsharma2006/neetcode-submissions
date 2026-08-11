class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double>st;
        vector<pair<int, int>> cars;
          for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
    sort(cars.begin(),cars.end());
        int n = speed.size();
        for(int i = n-1;i>=0;i--){
              double time = (double)(target - cars[i].first) / cars[i].second;
              if(!st.empty() && time<=st.top()){
                continue;
              }
                   st.push(time);
        }
        return st.size();
    }
};
