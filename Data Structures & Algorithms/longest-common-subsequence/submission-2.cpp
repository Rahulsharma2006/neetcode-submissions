class Solution {
public:
//    int helper(string text1 ,string text2 , int i , int j , int n , int m, vector<vector<int>>&dp){
//     if(i==n || j==m) return 0;
//     int val =0;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(text1[i]==text2[j]){
//         val=1+ helper(text1,text2,i+1,j+1,n ,m,dp);
//         return dp[i][j]= val;
//     }
//     int a = helper(text1,text2,i+1,j,n ,m,dp);
//     int b = helper(text1,text2,i,j+1,n ,m,dp);
//     return dp[i][j]=max(a,b);
//    }
     int tabulation(string text1, string text2, int n , int m){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         for(int i =n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                dp[i][j]=1+dp[i+1][j+1];
                }else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
         }
         return dp[0][0];
     }
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size()==0 || text2.size()==0)return 0;
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return  helper(text1,text2,0,0,n ,m,dp);
        return tabulation(text1,text2,n,m);
    }
};
