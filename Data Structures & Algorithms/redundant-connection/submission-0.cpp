
class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>>& adj, int n) {
        vector<bool> visited(n + 1, false);
        vector<int> parent(n + 1, -1);

        queue<int> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest) return true;

            for (int neigh : adj[node]) {

                if (!visited[neigh]) {
                    visited[neigh] = true;
                    parent[neigh] = node;
                    q.push(neigh);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // Check if path already exists
            if (bfs(u, v, adj, n)) {
                return edge;
            }

            // Add edge if no path exists
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};
