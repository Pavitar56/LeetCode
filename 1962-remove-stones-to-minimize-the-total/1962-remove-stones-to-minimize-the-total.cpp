class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq;
        
        for(int i=0;i<piles.size();i++)
        {
            pq.push(piles[i]);
        }
        
        
        while(k--)
        {
            int maximum = pq.top();
            pq.pop();
            
            maximum = maximum - (maximum/2);
            
            pq.push(maximum);
        }
        
        
        int sum =0;
        
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
        
    }
};