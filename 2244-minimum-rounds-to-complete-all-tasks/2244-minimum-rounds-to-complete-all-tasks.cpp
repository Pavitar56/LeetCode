class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
//         vector<int> time(100001);   //keeps track of min count taken to complet index i tasks
        
//         time[0] = -1;
//         time[1] = -1;
//         time[2] = 1;
//         time[3] = 1;
//         time[4] = 2;
        
//         for(int i=5;i<100001;i++)
//         {
//             time[i] = 1 + min(time[i-2],time[i-3]);
//         }
        
//         int count=0;
        
//         sort(tasks.begin(),tasks.end());
        
//         int si=0;
//         int ei=0;
        
//         while(ei<tasks.size())
//         {
//             while(ei<tasks.size() && tasks[si] == tasks[ei])
//             {
//                 ei++;
//             }
//             int repeat = ei - si;
//             if(repeat <= 1)
//             {
//                 return -1;
//             }
            
//             count+=time[repeat];
//             si=ei;
//         }
        
        
//         return count;
        
        unordered_map<int,int> freq;
        for(int i=0;i<tasks.size();i++)
        {
            
            freq[tasks[i]]++;
        }
        
        int ans=0;
        
        for (auto it =freq.begin();it!=freq.end();it++)
        {
            int frequency = it->second;
            if(frequency==1)
                return -1;
            if(frequency%3==0)
            {
                ans += frequency/3;
            }
            else
            {
                ans += frequency/3 + 1;
            }
        }
        return ans;
    }
        
        
        
    
};