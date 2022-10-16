class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        
        unordered_map<int,bool> map;
        int answer;
        for(int i=0;i<nums.size();i++)
        {
            if(map.count(nums[i]) > 0)
            {
                answer = nums[i];
            }
            
            map[nums[i]] = true;
        }
        
        return answer;
        
    }
};