class Solution {
public:
    int maximumSwap(int num) 
    {
        string temp = to_string(num);
        
        for(int i=0;i<temp.size();i++)
        {
            int maximum = INT_MIN;
            int idx = -1;
            for(int j=temp.size()-1; j>i ; j--)       //bcz i want farthest max digit
            {
                if(temp[j] > temp[i] && temp[j] > maximum)//in case of equal to i want farthest max right only
                {
                    maximum = temp[j];
                    idx = j;
                }
                
            }
            if(idx !=-1)
            {
                swap(temp[i],temp[idx]);
                break;
            }
        }
        
        return stoi(temp);
        
    }
};