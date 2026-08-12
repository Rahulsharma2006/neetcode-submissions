class Solution {
      vector<int> getRSN(vector<int>& heights ,int n){
     stack<int> st;
     vector<int> result(n, -1);
     for(int i =heights.size()-1;i>=0;i--){
        while(!st.empty()&&heights[st.top()]>=heights[i]){
            st.pop();
        }
         result[i] = st.empty() ? n : st.top();
        st.push(i);
     }
     return result;
    }
       vector<int>  getLSN(vector<int>& heights, int n){
     stack<int> st;
     vector<int> result(n, n);
     for(int i =0;i<heights.size();i++){
        while(!st.empty()&&heights[st.top()]>=heights[i]){
            st.pop();
        }
         result[i] = st.empty() ? -1 : st.top();
        st.push(i);;
     }
     return result;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
      vector<int> ne = getRSN(heights,n);
      vector<int> p= getLSN(heights,n);
      int ans =0;
      for(int i =0;i<n;i++){
        int width = ne[i] - p[i]-1;
        int currarea = heights[i] * width;
       ans = max(ans,currarea);
      }
  return ans;
    }
};