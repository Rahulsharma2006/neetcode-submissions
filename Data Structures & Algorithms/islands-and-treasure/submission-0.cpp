class Solution {
public:
  const int INF = 2147483647;
   bool valid(int row , int col , int n , int m){
    if(row<0 || row>=n || col<0 || col>=m)return false;
    return true;
   }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
   int x[4]={-1,0,1,0};
    int y[4]={0,-1,0,1};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i =0;i<4;i++){
                int row = r+x[i];
                int col = c + y[i];
                if(!valid(row,col,n,m)) continue;

                if(grid[row][col]==INF){
                    grid[row][col]=1+grid[r][c];
                    q.push({row,col});
                }
            }
        }
      
    }
};
