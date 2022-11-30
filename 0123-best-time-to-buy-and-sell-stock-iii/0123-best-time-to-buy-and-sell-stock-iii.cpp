class Solution {
public:
    int maxProfit(vector<int>& price) {
        
        vector<vector<int>> ahead(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        for(int idx = price.size() - 1;idx>=0;idx--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int transaction=1;transaction <= 2;transaction++)
                {
                     int profit=0;

                    if(buy)
                    {
                        profit = max( -price[idx] + ahead[0][transaction],ahead[1][transaction]);
                    }
                    else
                    {
                        profit = max(price[idx] + ahead[1][transaction-1],ahead[0][transaction]);
                    }

                    curr[buy][transaction]=profit;
                }
            }

            ahead=curr;
        }

        return ahead[1][2];
    }
};