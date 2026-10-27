class Solution {
public:
    bool valid(int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col)
            return false;
        return true;
    }
    int dfs(int i , int j , int n, int m ,
    vector<vector<bool>>& vis,vector<vector<int>>& grid){
       int res=1;
       vis[i][j]=true;
         int x[4] = {-1, 0, 1, 0};
        int y[4] = {0, -1, 0, 1};

        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
        if(valid(row,col,n,m) && grid[row][col]==1 && !vis[row][col]){
            res+=dfs(row,col,n,m,vis,grid);
        }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int ans =0;
        for(int i =0;i<n;i++ ){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans,dfs(i,j,n,m,vis,grid));
                }
            }
        }
        return ans;
    }
};
