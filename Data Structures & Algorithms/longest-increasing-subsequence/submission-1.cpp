class Solution {
public:
     int helper(int i , vector<int>& nums , int prev ,vector<vector<int>>&dp){
        //Base Case 
        if(i==nums.size())return 0;
        if(dp[i][prev+1]!=-1)return dp[i][prev+1];
        if(prev==-1 or nums[i]>nums[prev]){
            int c1= 1+ helper(i+1,nums,i,dp);
            int c2= helper(i+1,nums,prev,dp);
            return dp[i][prev+1] = max(c1,c2);
        } 
       return dp[i][prev+1] = helper(i+1,nums,prev,dp);
     }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(0,nums,-1,dp);
    }
};
