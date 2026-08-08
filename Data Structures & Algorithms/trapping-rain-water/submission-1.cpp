class Solution {
public:
    int trap(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
         int leftMax =0;
         int rightMax=0;
        int ans =0;
        while(low<high){
            if(height[low]<=height[high]){
                if(height[low]>=leftMax){
                    leftMax=height[low];
                }else{
                    ans+=leftMax-height[low];
                }
                low++;
            }else{
                if(height[high]>=rightMax){
                    rightMax=height[high];
                }else{
                    ans+=rightMax-height[high];
                }
                high--;
            }
        }
        return ans;
    }
};
