class Solution {
public:
    
    int solve(vector<pair<int,int>> &v,int ind,int maxScoreInd,vector<vector<int>> &dp)
    {
        
        if(ind == v.size())
        {
            return 0;
        }
        
        if(dp[ind][maxScoreInd+1] != -1)
        {
            return dp[ind][maxScoreInd+1];
        }
        
        int take = 0;
        if(maxScoreInd == -1)
        {
            take = v[ind].second + solve(v,ind+1,ind,dp);
        }
        else
        {
            int newMaxScoreInd = maxScoreInd;

            if(v[ind].second > v[maxScoreInd].second)
            {
                newMaxScoreInd = ind;
            }

            if(v[ind].first == v[maxScoreInd].first || v[ind].second >= v[maxScoreInd].second)
            {
                take = v[ind].second + solve(v,ind+1,newMaxScoreInd,dp);
            }
        
        }
        
        int not_take = 0;
        
        not_take = solve(v,ind+1,maxScoreInd,dp);
        
        return dp[ind][maxScoreInd+1]=max(take,not_take);
        
        
        
    }
    
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
//         vector<pair<int,int>> v(scores.size(),pair<int,int>());
//         //age,score
//         for(int i=0;i<scores.size();i++)
//         {
            
//             v[i].first = ages[i];
//             v[i].second = scores[i];
            
//         }
        
//         sort(v.begin(),v.end());
// 
//         vector<vector<int>> dp(v.size()+1,vector<int>(v.size()+1,-1));
//         int maximum = solve(v,0,-1,dp);
        
//         return maximum;
        
        //2nd approach LIS Approach
        int n = scores.size();
        int dp[n], ans = 0;
        
        vector<pair<int, int>> players;
        
        for(int i = 0; i < n; i++) 
            players.push_back({ages[i], scores[i]});
        
        sort(players.begin(), players.end());
        
        for(int i = 0; i < n; i++)
        {
            dp[i] = players[i].second;
            for(int j = i-1; j >= 0; j--) 
            {
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
        
        
    }
};