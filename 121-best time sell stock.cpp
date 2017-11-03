class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0,size = prices.size();
        if(size < 2) return 0;
        int min = prices[0];

        for(int i=1; i<size; i++){
            if(min > prices[i]) min = prices[i];
            else profit = max(profit,prices[i] - min);
        }
        return profit;
    }
};
