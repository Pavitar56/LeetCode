class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        int m = strs.size();
        int n =strs[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            string word = "";
            
            for(int j=0;j<m;j++)
            {
                word += strs[j][i];
            }
            
            string temp =word;
            sort(temp.begin(),temp.end());
            
            if(word != temp)
            {
                count++;
            }
            
        }
        
        return count;
        
    }
};