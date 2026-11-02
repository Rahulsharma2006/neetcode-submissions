class Solution {
public:
     int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        bool valid(int i , int j , int n , int m){
            if(i<0 || i>=n || j<0 || j>=m)return false;
            return true;
        }
//    void dfs(vector<vector<int>>& heights , int i , int j , int n , int m ,int prev,vector<vector<bool>>& Visited){
//     if(!valid(i,j,n,m))return;
//     if(heights[i][j]<prev || Visited[i][j]==true) return ;
//     Visited[i][j]=true;
//     for(int k=0;k<4;k++){
//         int r = i+x[k];
//         int c = j+y[k];
//         dfs(heights,r,c,n,m,heights[i][j],Visited);
//     }
    
//    }
   void bfs(vector<vector<int>>& heights, queue<pair<int,int>>&q,int n,int m,vector<vector<bool>>&Visited){
     while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int k =0;k<4;k++){
                int r = i+x[k];
                int c = j+y[k];
                if(!valid(r,c,n,m))continue;
                 if(heights[i][j]>heights[r][c] || Visited[r][c]==true) continue ;
                 Visited[r][c]=true;
                 q.push({r,c});
            }
         }
   }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacificVis(n,vector<bool>(m,false));
        vector<vector<bool>>atlanticVis(n,vector<bool>(m,false));
        queue<pair<int,int>> pq, aq;
        for(int i =0;i<m;i++){
              pacificVis[0][i]=true; //0,i.pacific
                 atlanticVis[n-1][i]=true; //n-1,i,atl
                 pq.push({0,i});
                 aq.push({n-1,i});
        }
                for(int i =0;i<n;i++){
             pacificVis[i][0]=true;//i,0,pac
              atlanticVis[i][m-1]=true;//i,m-1,atl
               pq.push({i,0});
               aq.push({i,m-1});
        }
         bfs(heights,pq,n,m,pacificVis);
         bfs(heights,aq,n,m,atlanticVis);
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(pacificVis[i][j] && atlanticVis[i][j] ) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
