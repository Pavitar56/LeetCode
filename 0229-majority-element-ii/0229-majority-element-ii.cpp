class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            
            map[nums[i]]++;
      
        }
        
        for(auto it= map.begin();it!= map.end(); it++)
        {
            int key = it->first;
            int val = it->second;
            
            if(val > (nums.size()/3))
            {
                ans.push_back(key);
            }
            
            
        }
        
        return ans;
    }
};