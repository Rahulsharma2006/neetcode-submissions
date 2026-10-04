class Solution {
public:
    //  int helper(vector<int>& nums , int i , int n ,vector<int>& dp){
    //     if(i>n)return 0;
    //     if(dp[i]!=-1)return dp[i];
    //     return dp[i]= max(nums[i]+helper(nums,i+2,n,dp),helper(nums,i+1,n,dp));
    //  }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
          vector<int>dp1(nums.size()+2,0);
          vector<int>dp2(nums.size()+2,0);
          int n = nums.size();
        // return max( helper(nums,0,n-2,dp1),helper(nums,1,n-1,dp2));
        for(int i =n-1;i>0;i--){
             dp1[i]=max(nums[i]+dp1[i+2],dp1[i+1]);
        }
          for(int i =n-2;i>=0;i--){
             dp2[i]=max(nums[i]+dp2[i+2],dp2[i+1]);
        }
        return max(dp1[1],dp2[0]);
    }
};
