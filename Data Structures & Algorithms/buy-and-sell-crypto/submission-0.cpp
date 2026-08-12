class Solution {
public:
   int Stocks(int i , int k , int n ,vector<int>& prices,vector<vector<int>>&dp){
    if(i==n || k==0)return dp[i][k]=0;
    if(dp[i][k]!=-1)return dp[i][k];
    if(k==2){
        int b1 = Stocks(i+1,k-1,n,prices,dp)-prices[i];
        int b2 = Stocks(i+1,k,n,prices,dp);
        return dp[i][k]=max(b1,b2);
    }else{
        int c1 =Stocks(i+1,k-1,n,prices,dp)+prices[i];
        int c2 = Stocks(i+1,k,n,prices,dp);
        return dp[i][k]=max(c1,c2);
    }
   }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return Stocks(0,2,n,prices,dp);
    }
};
