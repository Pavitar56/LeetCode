class Solution {
public:
    int lower_bound(vector<int> &fib,int k)
    {
        
        int start = 0;
        int end = fib.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(fib[mid] == k)
            {
                return mid;
            }
            else if(k < fib[mid])
            {
                end = mid-1;
            }
            else
            {
                start = mid +1;
            }
        }
        return start;
    }
    
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
            //int low = lower_bound(fib.begin(),fib.end(),k) - fib.begin();
            int low = lower_bound(fib,k);
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