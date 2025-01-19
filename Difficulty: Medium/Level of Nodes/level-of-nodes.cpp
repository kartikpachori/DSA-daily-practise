//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int nodeLevel(int V, vector<int> adj[], int X) {
        if (X >= V) return -1; // If X is out of bounds
        
        vector<bool> visited(V, false);
        queue<pair<int, int>> q; // Pair: (node, level)
        
        q.push({0, 0}); // Start BFS from node 0 at level 0
        visited[0] = true;

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int node = current.first;  // Access the node
            int level = current.second; // Access the level

            // If we find the target node
            if (node == X) {
                return level;
            }

            // Explore neighbors
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, level + 1});
                }
            }
        }

        return -1; // If X is not reachable
    }
};



//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends