class NumArray {
public:
    vector<int> preffixSum;
    vector<int> original;
    NumArray(vector<int>& nums)
    {
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            preffixSum.push_back(sum);
            original.push_back(nums[i]);
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left == 0)
        {
            return preffixSum[right];
        }
        
        return preffixSum[right] - preffixSum[left] + original[left];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */