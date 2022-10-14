class Solution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        
        int n = arr.size()-1;
        
        for(int j = n ; j>=0;j--)
        {
            if(arr[j] == 0)
            {
                
                
                for(int k = arr.size()-2; k>=j;k--)
                {
                    arr[k+1] =arr[k];
                }
                
                
                
            }
            
            
        }
        
        
    }
};