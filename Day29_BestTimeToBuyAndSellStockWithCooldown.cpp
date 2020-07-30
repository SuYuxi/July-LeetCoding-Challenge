class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int buy = -prices[0], sell = 0;
        int preSell = 0;
        for(int& price : prices)
        {
            int temp = sell;
            sell = max(sell, buy + price);
            buy = max(buy, preSell - price);
            preSell = temp;

            //buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
            //sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell;
    }
};
