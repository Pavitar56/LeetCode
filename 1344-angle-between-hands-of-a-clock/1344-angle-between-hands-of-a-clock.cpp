class Solution {
public:
    double angleClock(int hour, int minutes) 
    {
        double hourangle;
        if(hour == 12)
        {
            hourangle = 0.5 * minutes;
        }
        else
        {
            hourangle = (30.0 * hour) + (0.5 * minutes); 
        }
            
        
        double minuteangle = (6.0 * minutes);
        
        
        double poss1;
        double poss2;
        if(hourangle  >= minuteangle)
        {
            poss1 = hourangle - minuteangle;
        }
        else
        {
            poss1 = minuteangle - hourangle;
        }
        
        poss2 = 360 - poss1;
        
        return min(poss1,poss2);
        
        
    }
};