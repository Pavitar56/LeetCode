//stupidest question do not atmept this


class Solution {
public:
    bool isvalue(string s)
    {
        int len=s.length();
        
        if(len==1||s[0]!='$')
            return false;
        
        for(int i=1;i<len;i++)
        {
            if(!isdigit(s[i]))
                return false;
        }
        
        return true;
    }
    
    
    long double round(long double var)
    {
        long double value = (long long int)(var * 100 + .5);
        return (long double)value / 100;
    }
    
    string discountPrices(string sentence, int discount) 
    {
        double disc=discount*0.01;
        int len=sentence.length(),i=0,j;
        string res;
        
        while(i<len)
        {
            for(j=i ;j<len && sentence[j]!=' '; j++)
            {}
            
            string sub=sentence.substr(i,j-i);
            
            if(!isvalue(sub))
            {
                res+=sub;
            }
            else
            {

                long double val=stold(sub.substr(1));
                val=val-val*disc;
                val=round(val);
                 std::ostringstream streamObj3;
                
                streamObj3 << std::fixed;
                streamObj3 << std::setprecision(2);
                streamObj3 << val;
                
                std::string stemp = streamObj3.str();
                res+='$'+stemp.substr();
                streamObj3.clear();
            }
             res+=sentence[j];
            i=j+1;      
        }
        res.pop_back();
        return res;
    }
};