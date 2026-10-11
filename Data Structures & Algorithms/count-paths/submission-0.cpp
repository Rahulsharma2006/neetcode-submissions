class Solution {
public:
  //===============Memo=================//
   
    // int  Memorization(int m , int n , int i , int j,vector<vector<int>>&dp){

    //     if(i==n-1 && j==m-1){
    //         return 1;
    //     }
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int a=0;
    //     int b=0;
    //     if(i<n-1){
    //     a = Memorization(m,n,i+1,j,dp);
    //     }
    //     if(j<m-1){
    //     b = Memorization(m,n,i,j+1,dp);
    //     }
    //     return dp[i][j]= a+b;

    // }
 //=============================Tabuation============================//
   int tabulation(int m , int n ){
        vector<vector<int>>dp(n,vector<int>(m,1));
            for(int i=n-2;i>=0;i--){
                for(int j = m-2;j>=0;j--){
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
                }
            }
            return dp[0][0];
   }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(n+1,vector<int>(m,-1));
        //  return Memorization(m,n,0,0,dp);
        return tabulation(m,n);
    }
};