class Solution {
public:
    
    
    void helper(string &ans,int times, int carry,unordered_map<int,string> &map)
    {
        
        for(int i=1;i<=times;i++)
        {
            ans=map[carry] + ans;
        }
        
    }
    
    string intToRoman(int num) 
    {
        unordered_map<int,string> map;
        
        map={{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},{4,"IV"},{9,"IX"},{40,"XL"},                      {90,"XC"},{400,"CD"},{900,"CM"} };
        
        
        
        string ans;
        
        
        int pow=1;
        
        while(num!=0)
        {
            int digit = num%10;
            
            int curr=digit * pow;
            
            if(map.count(curr)>0)
            {
                ans = map[curr] + ans;
                num=num/10;
                pow=pow*10;
                continue;
            }
            
          
            if(pow == 1)
            {
                if(digit < 4)
                {
                    helper(ans,digit,1,map);
                }
                else
                {
                    helper(ans,digit-5,1,map);
                   ans=map[5]+ ans;
                }
               
            }
            else if(pow == 10)
            {
                 if(digit < 4)
                {
                     helper(ans,digit,10,map);
             
                }
                else
                {
                    helper(ans,digit-5,10,map);
                 
                   ans=map[50]+ ans;
                }  
            }
            else if(pow == 100)
            {
                if(digit < 4)
                {
                     helper(ans,digit,100,map);
             
                }
                else
                {
                    helper(ans,digit-5,100,map);
                 
                   ans=map[500]+ ans;
                }    
            }
            else if(pow == 1000)
            {
                if(digit < 4)
                {
                     helper(ans,digit,1000,map);
             
                }
       
            }
            pow=pow*10;
            num=num/10;
    
        }
        
        return ans;
        
    }
};