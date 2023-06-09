class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = '{';
        
        
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i] > target)
            {
                if(ans == '{')
                {
                    ans = letters[i];
                }
                else
                {
                    ans = min(ans,letters[i]);
                }
                
            }
            
        }
        if(ans == '{')
        {
            return letters[0];
        }
        
        return ans;
    }
};