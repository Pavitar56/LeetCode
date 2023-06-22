class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        vector<int> ahead(2,0),curr(2,0);
        for(int idx = price.size() - 1;idx>=0;idx--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                
                int profit=0;

                if(buy)
                {
                    profit = max( -price[idx] + ahead[0],ahead[1]);
                }
                else
                {
                    profit = max( -fee + price[idx] + ahead[1],ahead[0]);
                }

                curr[buy]=profit;
                
            }

            ahead=curr;
        }

        return ahead[1];
        
    }
};