class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        int r = mat.size();
        int c = mat[0].size();

        int low = 1;
        int high = 2000; // as per constraints

        while (low < high) {
            int mid = (low + high) / 2;
            int count = 0;

            // count number of elements <= mid
            for (int i = 0; i < r; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count < (r * c + 1) / 2)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
