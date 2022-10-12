class Solution {
public:
    int nextGreaterElement(int n) 
    {
        
       string arr = to_string(n);
 
    // Start from the right most digit and find the first
    // digit that is
    // smaller than the digit next to it.
    
        int i = 0;
    
        for (i = arr.size() - 1; i > 0; i--) 
        {
            if (arr[i] > arr[i - 1])
                break;
        }
        
        
 
    // If there is a possibility of a next greater element
    
        if (i != 0) 
        {
        // Find the smallest digit on right side of (i-1)'th
        // digit that is
        // greater than number[i-1]
            for (int j = arr.size() - 1; j >= i; j--) 
            {   
                if (arr[i - 1] < arr[j]) 
                {
                // Swap the found smallest digit i.e. arr[j]
                // with arr[i-1] 
                    swap(arr[i - 1], arr[j]);
                    break;       
                }  
            }
        }
        else
        {
            return -1;
        }
 
    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    
        sort(arr.begin() + i, arr.end());
        
        long long int ans = stoll(arr);
        if(ans> INT_MAX)
        {
            return -1;
        }
        
        return ans;
    
    }
};