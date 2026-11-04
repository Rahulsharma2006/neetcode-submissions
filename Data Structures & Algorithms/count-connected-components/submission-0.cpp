class Solution {
public:
    void bfs(vector<vector<int>>&adj,int node ,vector<bool>&vis){
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=true;
            for(int neigh : adj[node]){
                if(!vis[neigh]){
                    q.push(neigh);
                }
            }
        }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
       int ans =0;
       vector<vector<int>>adj(n);
       vector<bool>vis(n,false);
       for(auto edge : edges){
        int sr = edge[0];
        int dest = edge[1];
        adj[sr].push_back(dest);
        adj[dest].push_back(sr);
       }
       for(int i =0;i<adj.size();i++){
          if(!vis[i]){
            bfs(adj,i,vis);
            ans++;
          }
       }
       return ans;
    }
};
