class Solution {
  public:
    void dfsHelper(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& result) {
        visited[node] = 1;
        result.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, result);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        vector<int> result;
        
        dfsHelper(0, adj, visited, result);
        return result;
    }
};
