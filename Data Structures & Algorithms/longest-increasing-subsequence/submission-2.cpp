class Solution {
public:
    //  int helper(int i , vector<int>& nums , int prev ,vector<vector<int>>&dp){
    //     //Base Case 
    //     if(i==nums.size())return 0;
    //     if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    //     if(prev==-1 or nums[i]>nums[prev]){
    //         int c1= 1+ helper(i+1,nums,i,dp);
    //         int c2= helper(i+1,nums,prev,dp);
    //         return dp[i][prev+1] = max(c1,c2);
    //     } 
    //    return dp[i][prev+1] = helper(i+1,nums,prev,dp);
    //  }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        int n = nums.size();
        for(int curr = n-1 ; curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int include =0;
                if(prev==-1 || nums[curr]>nums[prev])
                include=1+dp[curr+1][curr+1];

                int exclude=dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include,exclude);
            }
        }
        return dp[0][0];
    }
};
