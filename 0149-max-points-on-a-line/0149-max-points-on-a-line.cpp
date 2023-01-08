class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        for(int i=0;i<points.size();i++)
        {
            for(int j=0;j<points.size();j++)
            {
                
                if(i==j)
                {
                    continue;
                }
                int count = 2;
                int y1 = (points[j][1] - points[i][1]);
                int x1=(points[j][0] - points[i][0]);
                for(int k=0;k<points.size();k++)
                {
                    if(j == k || i == k)
                    {
                        continue;
                    }
                    
                    
                    int y2 = (points[k][1] - points[j][1]);
                    int x2 = (points[k][0] - points[j][0]);
                    
                    if((y1 * x2) == (y2 * x1))
                    {
                        count++;
                    }
                    
                }
                
                ans= max(ans,count);
                
            }
            
        }
        return ans;
    }
};