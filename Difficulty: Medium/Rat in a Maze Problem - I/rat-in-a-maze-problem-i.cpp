//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move,
               vector<vector<int>> &vis, int di[], int dj[]) {
        // Base case: If we reach the bottom-right cell
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // Direction string
        string dir = "DLRU";

        // Try all 4 possible directions
        for (int idx = 0; idx < 4; idx++) {
            int nexti = i + di[idx];
            int nextj = j + dj[idx];

            // Check if the next cell is valid
            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] &&
                mat[nexti][nextj] == 1) {
                vis[i][j] = 1;
                solve(nexti, nextj, mat, n, ans, move + dir[idx], vis, di, dj);
                vis[i][j] = 0;
            }
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {+1, 0, 0, -1}; // Down, Left, Right, Up
        int dj[] = {0, -1, +1, 0};

        // Start solving if the starting cell is 1
        if (mat[0][0] == 1) solve(0, 0, mat, n, ans, "", vis, di, dj);

        // If no path is found, return {"-1"}
        if (ans.empty()) ans.push_back("-1");

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends