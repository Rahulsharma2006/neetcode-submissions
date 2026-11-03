class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto& pre : prerequisites){
            int a = pre[0];
            int b = pre[1];
            indegree[a]++;
            adj[b].push_back(a);
        }
        queue<int>q;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int finish =0;
        while(!q.empty()){
            finish++;
            int node = q.front();
            q.pop();
            for(int neigh : adj[node]){
               indegree[neigh]--;
               if(indegree[neigh]==0)q.push(neigh);
            }
        }
        return finish == numCourses;
    }
};
