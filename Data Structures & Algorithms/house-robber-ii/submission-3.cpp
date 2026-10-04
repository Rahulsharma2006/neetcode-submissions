class Solution {
public:
     int helper(vector<int>& nums , int i , int n ,vector<int>& dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i]= max(nums[i]+helper(nums,i+2,n,dp),helper(nums,i+1,n,dp));
     }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
          vector<int>dp1(nums.size()+1,-1);
          vector<int>dp2(nums.size()+1,-1);
          int n = nums.size();
        return max( helper(nums,0,n-1,dp1),helper(nums,1,n,dp2));
    }
};
