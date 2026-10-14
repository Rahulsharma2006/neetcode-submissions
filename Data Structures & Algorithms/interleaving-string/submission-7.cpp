class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s3.size()+1,vector<int>(s3.size()+1,-1));
        return dfs(0, 0, 0, s1, s2, s3,dp);
    }
    bool Tabulation(string s1, string s2, string s3){
        vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i =s1.size();i>=0;i--){
            for(int j=s2.size();j>=0;j--){
                if(i<s1.size() && s1[i]==s3[i+j]&&dp[i+1][j])dp[i][j]=true;

                if(j<s2.size() && s2[j]==s3[i+j] && dp[i][j+1])dp[i][j]=true;
            }
        }
        return dp[0][0];

    }
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>&dp) {
        if (k == s3.length()) {
            return (i == s1.length()) && (j == s2.length());
        }
             if(dp[i][j]!=-1)return dp[i][j];
        if (i < s1.length() && s1[i] == s3[k]) {
            if (dfs(i + 1, j, k + 1, s1, s2, s3,dp)) {
                return dp[i][j]=true;
            }
        }

        if (j < s2.length() && s2[j] == s3[k]) {
            if (dfs(i, j + 1, k + 1, s1, s2, s3,dp)) {
                return dp[i][j]=true;
            }
        }

        return dp[i][j]=false;
    }
};