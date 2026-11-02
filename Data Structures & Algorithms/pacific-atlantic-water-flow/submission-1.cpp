class Solution {
public:
     int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        bool valid(int i , int j , int n , int m){
            if(i<0 || i>=n || j<0 || j>=m)return false;
            return true;
        }
   void dfs(vector<vector<int>>& heights , int i , int j , int n , int m ,int prev,vector<vector<bool>>& Visited){
    if(!valid(i,j,n,m))return;
    if(heights[i][j]<prev || Visited[i][j]==true) return ;
    Visited[i][j]=true;
    for(int k=0;k<4;k++){
        int r = i+x[k];
        int c = j+y[k];
        dfs(heights,r,c,n,m,heights[i][j],Visited);
    }
    
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacificVis(n,vector<bool>(m,false));
        vector<vector<bool>>atlanticVis(n,vector<bool>(m,false));
        for(int i =0;i<m;i++){
            dfs(heights,0,i,n,m,INT_MIN,pacificVis);
            dfs(heights,n-1,i,n,m,INT_MIN,atlanticVis);
        }
                for(int i =0;i<n;i++){
            dfs(heights,i,0,n,m,INT_MIN,pacificVis);
            dfs(heights,i,m-1,n,m,INT_MIN,atlanticVis);
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(pacificVis[i][j] && atlanticVis[i][j] ) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
