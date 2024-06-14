//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>& arr, int x) {
        int left = 0;
        int right = arr.size() - 1;
        int closest_sum = arr[left] + arr[right];
        int best_left = left, best_right = right;

        while (left < right) {
            int current_sum = arr[left] + arr[right];

            // Update the closest sum and best pair if this pair is closer to X
            if (abs(current_sum - x) < abs(closest_sum - x)) {
                closest_sum = current_sum;
                best_left = left;
                best_right = right;
            }

            // Move the pointers based on the current sum
            if (current_sum < x) {
                left++;
            } else {
                right--;
            }
        }

        return {arr[best_left], arr[best_right]};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends