class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>>adj(numCourses);
      vector<int>indegree(numCourses,0);
      for(auto pre : prerequisites){
        int a = pre[0];
        int b = pre[1];
        //b-->a
        adj[b].push_back(a);
        indegree[a]++;
      }
      queue<int>q;
      int finish =0;
      for(int i =0;i<numCourses;i++){
        if(indegree[i]==0)q.push(i);
      }
      vector<int>res;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);
        finish++;
        for(int neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh]==0) q.push(neigh);
        }
      }
      if(finish == numCourses) return res;

      return {};
    }
};
