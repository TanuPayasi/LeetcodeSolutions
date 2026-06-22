class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int hold= -prices[0];
        int nothold= 0;
        for(int i=1;i<n;i++){
            int newhold= max(hold, nothold-prices[i]);
            int newnothold= max(nothold, hold+prices[i]);
            hold=newhold;
            nothold=newnothold;
        }

        return nothold;
    }
};