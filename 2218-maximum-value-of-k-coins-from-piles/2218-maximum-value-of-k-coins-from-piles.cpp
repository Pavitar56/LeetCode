class Solution {
public:
     //startPileIdx is always 0
    //piles under consideration for each call ==> [pileIdx = 0 to pileIdx = endPileIdx]
    int solve(vector<vector<int>>&piles, vector<vector<int>>&dp, int endPileIdx, int k)
    {
        if (endPileIdx < 0 || k == 0) return 0;
        if (dp[endPileIdx][k] != -1) return dp[endPileIdx][k];
        
        int currPileSize = piles[endPileIdx].size(); 
        int maxCanPick = min(k, currPileSize);
        
        //consider 'not picking' any coin
        int maxSum = solve(piles, dp, endPileIdx - 1, k);  //DON'T PICK ANY COIN FROM CURR PILE
        int pickedSum = 0;
        //===============================================================================
        //now consider picking some coins
        for (int i = 0; i < maxCanPick; i++)
        {
            int coinValue = piles[endPileIdx][i];
            pickedSum += coinValue;
            
            int nextMaxSum = solve(piles, dp, endPileIdx - 1, k - i - 1); 
            maxSum = max(maxSum, pickedSum + nextMaxSum);
        }
        //=================================================================================
        return dp[endPileIdx][k] = maxSum;
        
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        int ans = solve(piles, dp, n - 1, k);
        return ans;
    }
};