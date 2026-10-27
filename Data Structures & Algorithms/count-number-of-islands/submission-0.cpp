class Solution {
public:
    bool valid(int i , int j , int row , int col){
        if(i<0 || j<0 || i>=row || j>=col)return false;

        return true;
    }
     void dfs(int i , int j , int n , int m ,                                       vector<vector<bool>>&vis,vector<vector<char>>& grid){
          vis[i][j]=true;
          int x[4] = {-1, 0, 1, 0};
          int y[4] = {0, -1, 0, 1};
          for(int k =0;k<4;k++){
            int row = i+x[k];
            int col =j+y[k];
            if(valid(row,col,n,m) && !vis[row][col]&& grid[row][col]=='1'){
                dfs(row,col,n,m,vis,grid);
            }
          }
     }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,n,m,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};
