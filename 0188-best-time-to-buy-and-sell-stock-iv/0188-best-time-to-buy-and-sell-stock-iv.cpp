class Solution {
public:
    int maxProfit(int k, vector<int>& price) {
        
        vector<vector<int>> ahead(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        for(int idx = price.size() - 1;idx>=0;idx--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                for(int transaction=1;transaction <= k;transaction++)
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

        return ahead[1][k];
    }
};