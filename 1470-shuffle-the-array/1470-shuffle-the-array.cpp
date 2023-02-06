class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int i=0;
        int j=n;
        vector<int> ans(n*2);
        int k=0;
        while(j < nums.size())
        {
            ans[k++] = nums[i];
            ans[k++] = nums[j];
            i++;
            j++;
        }
        
        return ans;
        
    }
};