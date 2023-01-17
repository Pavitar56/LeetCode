class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> countOnesInLeft(n,0);
        vector<int> countZeroesInRight(n,0);
        
        int ones = 0;
        for(int i=0;i<n;i++)        // preSum of 1's
        {
            if(s[i]=='1')
                ones++;
            countOnesInLeft[i] = ones;
        }
        int zeroes = 0;
        for(int i=n-1;i>=0;i--)     //Suffix sum of 0's
        {
            if(s[i]=='0')
                zeroes++;
            countZeroesInRight[i] = zeroes;
        }
        
        int totalFlips = INT_MAX;
        for(int cut=0;cut<n-1;cut++)
        {
            int flipsInLeft = countOnesInLeft[cut];
            int flipsInRight = countZeroesInRight[cut+1];
            totalFlips = min(totalFlips,flipsInLeft+flipsInRight);
        }
        
        //cut before index 0   i.e    convert all 0's to 1's 
        totalFlips = min(totalFlips,countZeroesInRight[0]);
        
        //cut after index (n-1)   i.e  convert all 1's to 0's 
        totalFlips = min(totalFlips,countOnesInLeft[n-1]);
        
        return totalFlips;
        
    }
};