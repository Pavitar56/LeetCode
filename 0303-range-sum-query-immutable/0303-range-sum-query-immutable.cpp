class NumArray {
public:
    vector<int> preffixSum;    // prefixSum[i] =sum from 0 to i-1 
    NumArray(vector<int>& nums)
    {
        int sum=0;
        
        preffixSum.push_back(0);
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            preffixSum.push_back(sum);
            
        }
    }
    
    int sumRange(int left, int right) 
    {
      
        
        return preffixSum[right+1] - preffixSum[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */