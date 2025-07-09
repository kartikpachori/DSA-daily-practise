class Solution {
  public:
    long long power(long long x, int n, int m) {
        long long result = 1;
        for (int i = 1; i <= n; i++) {
            result *= x;
            if (result > m) return result; // early stop to avoid overflow
        }
        return result;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;

        while (low <= high) {
            int mid = (low + high) / 2;
            long long midPower = power(mid, n, m);

            if (midPower == m)
                return mid;
            else if (midPower < m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return -1; // no integer root found
    }
};
