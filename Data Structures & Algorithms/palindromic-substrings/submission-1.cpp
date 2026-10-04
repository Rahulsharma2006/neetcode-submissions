class Solution {
public:
    bool solve(int i , int j , string &s,vector<vector<int>>&dp){
        if(i>=j)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j]) return dp[i][j]=solve(i+1,j-1,s,dp);
        return dp[i][j] =0;

     }
    int countSubstrings(string s) {
        int ans =0;
        int n = s.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n;i++){
            for(int j =i;j<n;j++){
                if(solve(i,j,s,dp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
