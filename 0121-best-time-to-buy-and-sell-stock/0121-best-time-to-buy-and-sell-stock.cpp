class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int leastSoFar=INT_MAX;
        int profitSoFar=0;
        int overallProfit=0;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<leastSoFar)
            {
                leastSoFar=prices[i];
            }
            
            profitSoFar=prices[i]-leastSoFar;
            
            if(profitSoFar>overallProfit)
            {
                overallProfit=profitSoFar;
            }
            
            
        }
        
        if(overallProfit<=0)
        {
            return 0;
        }
        
        return overallProfit;
        
    }
};