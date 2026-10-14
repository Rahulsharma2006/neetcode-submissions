class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s3.size()+1,vector<int>(s3.size()+1,-1));
        return dfs(0, 0, 0, s1, s2, s3,dp);
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