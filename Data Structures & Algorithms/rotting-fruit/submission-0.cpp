class Solution {
public:
   bool valid(int row , int col , int n , int m){
    if(row<0 || col<0 || row>=n || col>=m){
        return false;
    }
    return true;
   }
    int orangesRotting(vector<vector<int>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        int fresh =0;
        int time =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty() && fresh>0){
            time++;
            int size= q.size();
            while(size--){
                auto [r,c]=q.front();
                  q.pop();
                  for(int k =0;k<4;k++){
                    int row = r+x[k];
                    int col = c+y[k];
                    if(valid(row,col,n,m) && grid[row][col]==1){
                        fresh--;
                        grid[row][col]=2;
                        q.push({row,col});
                    }
                  }
            }

        }
        if(fresh>0)return -1;
        return time;
    }
};
