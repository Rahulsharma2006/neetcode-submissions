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
  int Tabulation(int amount, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
            for (int i = 0; i <= n; i++) {
              dp[i][0] = 1;
              }
        for(int i=n-1;i>=0;i--){
            for(int a =1;a<=amount;a++){
                dp[i][a]=dp[i+1][a];
                if(a>=coins[i]) dp[i][a]+=dp[i][a-coins[i]];
            }
        }
         return dp[0][amount];
  }
    int change(int amount, vector<int>& coins) {
        // int n = coins.size();
        // vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        // return helper(amount,coins,0,dp);
        return Tabulation(amount,coins);
    }
};
