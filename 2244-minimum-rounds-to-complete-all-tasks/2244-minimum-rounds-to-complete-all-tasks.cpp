class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        vector<int> time(100001);
        
        time[0] = -1;
        time[1] = -1;
        time[2] = 1;
        time[3] = 1;
        time[4] = 2;
        
        for(int i=5;i<100001;i++)
        {
            time[i] = 1 + min(time[i-2],time[i-3]);
        }
        
        int count=0;
        
        sort(tasks.begin(),tasks.end());
        
        int si=0;
        int ei=0;
        
        while(ei<tasks.size())
        {
            while(ei<tasks.size() && tasks[si] == tasks[ei])
            {
                ei++;
            }
            int repeat = ei - si;
            if(repeat <= 1)
            {
                return -1;
            }
            
            count+=time[repeat];
            si=ei;
        }
        
        
        return count;
        
        
        
    }
};