class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        int count=0;
        int len=flowerbed.size();
        
        if(len==1 && flowerbed[0]==0)
        {
            if(n<=1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(len>=2 && flowerbed[0]==0 && flowerbed[1]==0)
        {
            flowerbed[0]=1;
            count++;
        }
        
        for(int i=1;i<len-1;i++)
        {
            if(flowerbed[i]==0)
            {
                
                if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    count++;
                }
                
                
                if(count>=n)
                {
                    return true;
                }
                     
            }
           
        }
        
        if(len>=2 && flowerbed[len-2]==0 && flowerbed[len-1]==0)
        {
            flowerbed[len-1]=1;
            count++;
        }
        if(count>=n)
        {
            return true;
        }
        
        return false;
    }
};