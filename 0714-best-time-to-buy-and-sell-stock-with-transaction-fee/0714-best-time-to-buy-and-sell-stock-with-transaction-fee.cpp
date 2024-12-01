class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int hold = -prices[0];
        int notHold = 0;
        for (int i = 1; i < n; i++) {
            hold = max(hold, notHold - prices[i]);
            notHold = max(notHold, hold + prices[i] - fee);
        }
        return notHold;
    }
};
