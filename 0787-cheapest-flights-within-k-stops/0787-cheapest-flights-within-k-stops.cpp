class Solution {
public:
    
   
    
    
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        
        for(int i=0;i<flights.size();i++)
        {
            //source-> {dest,price}
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        
        
        //{{num flights,price},node}
    priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
        
        
        vector<int> totalPrice(n,INT_MAX);
     
        pq.push({{0,0},src});
       
        
        while(!pq.empty())
        {
            
            int num_flights = pq.top().first.first;
            int price = pq.top().first.second;
            int node = pq.top().second;
            
            pq.pop();
            
            if(num_flights > k)
            {
                break;
            }
            
            for(int i=0;i<adj[node].size();i++)
            {
                
                int nNode = adj[node][i].first;
                int nPrice = adj[node][i].second;
                
                if((price + nPrice) < totalPrice[nNode])
                {
                    totalPrice[nNode] = price + nPrice;
                    pq.push({{num_flights + 1,totalPrice[nNode]},nNode});
                }
            }
            
        }
        
        
        
        return totalPrice[dst] != INT_MAX ? totalPrice[dst] : -1;
        
        
        
    }
};