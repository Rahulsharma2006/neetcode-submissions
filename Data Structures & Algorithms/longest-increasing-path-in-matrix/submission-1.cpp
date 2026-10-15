class Solution {
public:
   int x[4]={-1,1,0,0};
   int y[4]={0,0,-1,1};
  int dfs(vector<vector<int>>& matrix,int row, int col , int prev,vector<vector<int>>&dp){
    int n = matrix.size();
    int m = matrix[0].size();
    if(row<0 || row>=n || col<0 || col>=m || matrix[row][col]<=prev) return 0;
    if(dp[row][col]!=-1)return dp[row][col];
    int res=1;
    for(int k =0;k<4;k++){
        int newrow = row+x[k];
        int newcol= col +y[k];
        res=max(res,1+dfs(matrix,newrow,newcol,matrix[row][col],dp));
    }
      return dp[row][col]=res;
  }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans =0;
        vector<vector<int>>dp(n+1,vector<int>(m,-1));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                ans=max(ans,dfs(matrix,i,j,INT_MIN,dp));
            }
        }
        return ans;
    }
};
