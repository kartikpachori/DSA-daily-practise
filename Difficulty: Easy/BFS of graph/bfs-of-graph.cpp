class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0); // 0: unvisited, 1: visited
        vector<int> result;
        queue<int> q;

        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }

        return result;
    }
};
