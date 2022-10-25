class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        int num = 0;
        
        while(target != 1)
        {
            
            if(target % 2 == 0 && maxDoubles > 0)
            {
                target /= 2;
                maxDoubles--;
                num++;
            }
            else if(maxDoubles == 0)
            {
                num += target  - 1;
                target = 1;
            }
            else
            {
                num++;
                target -= 1;
            }
                
            
            
        }
        
        return num;
        
    }
};