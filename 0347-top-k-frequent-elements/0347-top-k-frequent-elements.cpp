class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> map;
        
        
        for(int i=0;i<nums.size();i++)
        {
            map[nums[i]]++;   
        }
        
        
        priority_queue<pair<int,int> , vector<pair<int,int>> ,greater<pair<int,int>>> pq;
        int count=0;
        
        for(unordered_map<int,int>::iterator it = map.begin(); it != map.end(); it++)
        {
            if(count == k)
            {
                if(pq.top().first < it->second)
                {
                    pq.pop();
                    pq.push({it->second,it->first});
                }
            }
            else
            {
                pq.push({it->second,it->first});
                count++;
            }
            
        }
        
        
        vector<int> ans;
        
        while(!pq.empty())
        {
            pair<int,int> p1=pq.top();
            ans.push_back(p1.second);
            pq.pop();
        }
        return ans;
        
    }
};