class Solution {
  public:
  int knap(int W,vector<int> &val, vector<int> &wt, int n,vector<vector<int>>& dp){
      
      if(n==0||W==0){
          return 0;
      }
      if(dp[n][W]!=-1){
          return dp[n][W];
      }
      if (wt[n-1]<=W){
          dp[n][W]=max(val[n-1]+knap(W-wt[n-1],val,wt,n-1,dp),knap(W,val,wt,n-1,dp));
          return dp[n][W];
      }
      
      else {
          dp[n][W]=knap(W,val,wt,n-1,dp);
          return dp[n][W];
      }
  }
  
  
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W + 1, -1));    
    
        return knap(W,val,wt,n,dp);
        
        
    }
};