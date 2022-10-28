class Solution {
public:
    int findMinFibonacciNumbers(int k) 
    {
        vector<int> fib;
        int a=0;
        int b=1;
        
        while((a+b) <= 1000000007)
        {
            int c = a+b;
            fib.push_back(c);
            
            a=b;
            b=c;
        }
        int count =0;
        while(k !=0)
        {
            int low = lower_bound(fib.begin(),fib.end(),k) - fib.begin();
            
            if(fib[low] == k)
            {
                k=0;
            }
            else
            {
                k -= fib[low-1];
            }
            
            count++;
        }
        
        return count;
    }
};