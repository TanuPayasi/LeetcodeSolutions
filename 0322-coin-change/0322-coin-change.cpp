class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0) return -1;
        if(amount==0) return 0;
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=coins[i];j<=amount;j++){
                if(dp[j-coins[i]]!=INT_MAX-1) dp[j]=min(dp[j],1+dp[j-coins[i]]);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};