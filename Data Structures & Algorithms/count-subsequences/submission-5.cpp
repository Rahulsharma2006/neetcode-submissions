class Solution {
public:
  int Memorization(string s , string t , int i , int j,vector<vector<int>>&dp){
    if(j==t.size())return 1;
    if(i==s.size())return 0;
       if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j]=Memorization(s,t,i+1,j,dp)+Memorization(s,t,i+1,j+1,dp);
    }else{
        return dp[i][j]=Memorization(s,t,i+1,j,dp);
    }
  }
   int tabulation(string s , string t){
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
    for(int i =0 ; i<=s.size();i++){
               dp[i][t.size()]=1;
    }
    for(int i = s.size()-1;i>=0;i--){
        for(int j = t.size()-1;j>=0;j--){
            if(s[i]==t[j]){
                dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
            }else{
                dp[i][j]=dp[i+1][j];
            }
        }
    }
    return dp[0][0];
   }
    int numDistinct(string s, string t) {
    //     vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
    //   return Memorization(s,t,0,0,dp);
    return (int)tabulation(s, t);
    }
};
