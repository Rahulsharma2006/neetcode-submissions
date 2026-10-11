class Solution {
public:
      int Memo(int i , int buying ,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=prices.size()) return 0;
        int buy=0;
        int sell=0;
        if(dp[i][buying]!=-1)return dp[i][buying];
        int leave =  Memo(i+1,buying,prices,dp);
        if(buying){
             buy = Memo(i+1,0,prices,dp)-prices[i];
        }else{
            sell = Memo(i+2,1,prices,dp)+prices[i];
        }
        return dp[i][buying]=max(buy,max(sell,leave));
      }
      int tabulation(vector<int>& prices){
         vector<vector<int>>dp(prices.size(),vector<int>(2,0));
           int n = prices.size();
         for(int i = n-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                dp[i][j]=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+2][j]));
            }
         }
         return dp[0][0];
      }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return Memo(0,1,prices,dp);
    }
};
