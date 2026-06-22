class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int hold = -prices[0];
    int notHold = 0;
    for (int i = 1; i < n; i++) {
        int newHold = max(hold, notHold - prices[i]);
        int newNotHold = max(notHold, hold + prices[i] - fee);
        hold = newHold;
        notHold = newNotHold;
    }
    return notHold;
}
};