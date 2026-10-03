class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==0 || n==1)return nums[0];
        int ans =-1;
        
        int prev=nums[n-1];
        int prev_prev=0;
        for(int i = n-2 ;i>=0;i--){
            ans=max(nums[i]+prev_prev,prev);
            prev_prev=prev;
            prev=ans;
        }
        return ans;
    }
};