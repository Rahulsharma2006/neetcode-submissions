class Solution {
public:
  int helper(int amount, vector<int>& coins, int i, vector<vector<int>>&dp){
         if(amount==0)
            return 1;
             if(i>=coins.size() || amount<0)
             return 0;
             if(dp[i][amount]!=-1)return dp[i][amount];
     return dp[i][amount]= helper(amount, coins, i + 1,dp) + helper(amount - coins[i], coins, i,dp);

  }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return helper(amount,coins,0,dp);
    }
};
